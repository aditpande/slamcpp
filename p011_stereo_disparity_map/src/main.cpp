#include "commons.hpp"
#include "stereo.hpp"
#include "viewer.hpp"

using namespace std;

int main(int argc, char **argv) {

  char *left_image_path = argv[1];
  char *right_image_path = argv[2];

  // stereo camera intrinsics
  const stereo::stereo_camera_intrinsics_t stereo_camera_intrinsics = {
      .left = {.fx = 3979.911, .fy = 3979.911, .cx = 1244.772, .cy = 1019.507},
      .right = {.fx = 3979.911, .fy = 3979.911, .cx = 1369.115, .cy = 1019.507},
      .baseline = 193.001};

  std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
      pointcloud;

  stereo::getPointCloudFromStereoImagePair(
      left_image_path, right_image_path, stereo_camera_intrinsics, pointcloud);
  return 0;
}
