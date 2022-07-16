#include "commons.hpp"
#include "stereo.hpp"
#include "viewer.hpp"

using namespace std;

int main(int argc, char **argv) {

  //   char *left_image_path = argv[1];
  //   char *right_image_path = argv[2];

  char *left_image_path = (char *)"../data/im_left.png";
  char *right_image_path = (char *)"../data/im_right.png";

  // stereo camera intrinsics
  const stereo::stereo_camera_intrinsics_t stereo_camera_intrinsics = {
      .left = {.fx = 3979.911, .fy = 3979.911, .cx = 1244.772, .cy = 1019.507},
      .right = {.fx = 3979.911, .fy = 3979.911, .cx = 1369.115, .cy = 1019.507},
      .baseline = 193.001};

  cv::Mat left_image;
  cv::Mat right_image;
  stereo::readStereoImagePairFromFiles(left_image_path, right_image_path,
                                       left_image, right_image);

  //   stereo::getPointCloudFromStereoImagePair(
  //       left_image_path, right_image_path, stereo_camera_intrinsics,
  //       pointcloud);

  cv::Mat rectified_left_image;
  cv::Mat rectified_right_image;
  stereo::uncalibratedStereoRectification(
      left_image, right_image, rectified_left_image, rectified_right_image);

  cv::imshow("rectified_left_image", rectified_left_image);
  cv::imshow("rectified_right_image", rectified_right_image);
  cv::waitKey(0);

  cv::destroyAllWindows();

  std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
      pointcloud;

  stereo::getPointCloudFromStereoImagePair(
      rectified_left_image, rectified_right_image, stereo_camera_intrinsics,
      pointcloud);

  viewer::showPointCloud(pointcloud);

  return 0;
}
