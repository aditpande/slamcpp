#include "stereo.hpp"
#include "commons.hpp"

void stereo::readStereoImagePairFromFiles(const char *left_image_path,
                                          const char *right_image_path,
                                          cv::Mat &left_image,
                                          cv::Mat &right_image) {
  left_image = cv::imread(left_image_path, cv::IMREAD_GRAYSCALE);
  if (left_image.empty()) {
    std::cerr << "Left image could not be read\n";
  }

  right_image = cv::imread(right_image_path, cv::IMREAD_GRAYSCALE);
  if (right_image.empty()) {
    std::cerr << "Right image could not be read\n";
  }
}

void stereo::uncalibratedStereoRectification(const cv::Mat &left_image,
                                             const cv::Mat &right_image,
                                             cv::Mat &left_rectified_img,
                                             cv::Mat &right_rectified_img) {
  cv::Ptr<cv::ORB> orb = cv::ORB::create();

  std::vector<cv::KeyPoint> l_kps;
  cv::Mat l_descriptors;
  orb->detectAndCompute(left_image, cv::noArray(), l_kps, l_descriptors);

  std::vector<cv::KeyPoint> r_kps;
  cv::Mat r_descriptors;
  orb->detectAndCompute(right_image, cv::noArray(), r_kps, r_descriptors);

  cv::Ptr<cv::DescriptorMatcher> matcher =
      cv::DescriptorMatcher::create(cv::DescriptorMatcher::BRUTEFORCE_HAMMING);

  std::vector<std::vector<cv::DMatch>> knn_matches;

  matcher->knnMatch(l_descriptors, r_descriptors, knn_matches, 2);
  // l is query; r is train

  //-- Filter matches using the Lowe's ratio test
  std::vector<cv::Point2f> _lpts;
  std::vector<cv::Point2f> _rpts;

  const float ratio_thresh = 0.7f;
  std::vector<cv::DMatch> good_matches;
  for (size_t i = 0; i < knn_matches.size(); i++) {
    if (knn_matches[i][0].distance <
        ratio_thresh * knn_matches[i][1].distance) {
      good_matches.push_back(knn_matches[i][0]);

      _lpts.push_back(l_kps[knn_matches[i][0].queryIdx].pt);

      _rpts.push_back(r_kps[knn_matches[i][0].trainIdx].pt);
    }
  }

  cv::Mat inliers;
  cv::Mat fundamental_matrix =
      cv::findFundamentalMat(_lpts, _rpts, inliers, cv::FM_RANSAC);

  std::cout << "output_mask.rows:" << inliers.rows << std::endl;
  std::cout << "output_mask.cols:" << inliers.cols << std::endl;

  std::vector<cv::Point2f> lpts;
  std::vector<cv::Point2f> rpts;

  for (size_t i = 0; i < inliers.rows; i++) {
    if (inliers.ptr<uchar>(i)[0] == 1) { // kill outliers in RANSAC
      lpts.push_back(_lpts[i]);
      rpts.push_back(_rpts[i]);
    }
  }

  cv::Mat H1;
  cv::Mat H2;
  cv::stereoRectifyUncalibrated(lpts, rpts, fundamental_matrix,
                                left_image.size(), H1, H2);

  cv::warpPerspective(left_image, left_rectified_img, H1, left_image.size());
  cv::warpPerspective(right_image, right_rectified_img, H2, right_image.size());
}

void stereo::getPointCloudFromStereoImagePair(
    const cv::Mat &left_image, const cv::Mat &right_image,
    const stereo::stereo_camera_intrinsics_t &camera_intrinsics,
    std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
        &pointcloud) {

  int channels = left_image.channels();

  /**
   * @brief SGBM parameters
   * reference: https://docs.opencv.org/4.6.0/d2/d85/classcv_1_1StereoSGBM.html
   */
  const int minDisparity = 0;
  const int numDisparities = 96;
  const int blockSize = 5;
  const int P1 = 8 * channels * blockSize * blockSize;
  const int P2 = 32 * channels * blockSize * blockSize;
  const int disp12MaxDiff = 1;
  const int preFilterCap = 63;
  const int uniquenessRatio = 10;
  const int speckleWindowSize = 100;
  const int speckleRange = 2;
  const int mode = cv::StereoSGBM::MODE_SGBM;

  cv::Ptr<cv::StereoSGBM> sgbm = cv::StereoSGBM::create(
      minDisparity, numDisparities, blockSize, P1, P2, disp12MaxDiff,
      preFilterCap, uniquenessRatio, speckleWindowSize, speckleRange, mode);

  cv::Mat disparity_sgbm;
  sgbm->compute(left_image, right_image, disparity_sgbm);

  cv::Mat disparity;
  disparity_sgbm.convertTo(disparity, CV_32F, 1.0 / 16.0f);

  cv::imshow("disparity", disparity / 96.0);
  cv::waitKey(0);
  cv::destroyWindow("disparity");

  const int irows = left_image.rows;
  const int icols = left_image.cols;
  const int ichas = left_image.channels();

  for (std::size_t v = 0; v < irows; v++) {
    for (std::size_t u = 0; u < icols; u++) {

      if (disparity.at<float>(v, u) <= 10.0 ||
          disparity.at<float>(v, u) >= 96.0) {
        continue;
      }

      // point as (x, y, z, color)
      Eigen::Vector4d point(0, 0, 0, left_image.at<uchar>(v, u) / 255.0);
      double x = (u - camera_intrinsics.left.cx) / camera_intrinsics.left.fx;
      double y = (v - camera_intrinsics.left.cy) / camera_intrinsics.left.fy;
      double depth = camera_intrinsics.left.fx * camera_intrinsics.baseline /
                     (disparity.at<float>(v, u));

      point[0] = x * depth;
      point[1] = y * depth;
      point[2] = depth;
      pointcloud.push_back(point);
    }
  }
}