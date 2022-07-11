#include "stereo.hpp"
#include "commons.hpp"

void stereo::getPointCloudFromStereoImagePair(
    const char *left_image_path, const char *right_image_path,
    const stereo::stereo_camera_intrinsics_t &camera_intrinsics,
    std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
        &pointcloud) {
  cv::Mat left_image = cv::imread(left_image_path, cv::IMREAD_GRAYSCALE);
  cv::Mat right_image = cv::imread(right_image_path, cv::IMREAD_GRAYSCALE);

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

  const int irows = left_image.rows;
  const int icols = left_image.cols;
  const int ichas = left_image.channels();
  for (std::size_t v = 0; v < irows; v++) {
    for (std::size_t u = 0; u < icols; v++) {
      if (disparity.at<float>(v, u) <= 10.0 ||
          disparity.at<float>(v, u) >= 96.0) {
        continue;
      }

      // point as (x, y, z, color)
      Eigen::Vector4d point(0, 0, 0, left_image.at<uchar>(v, u) / 255.0);
      //   double x = (u - cx) / fx;
    }
  }
}
