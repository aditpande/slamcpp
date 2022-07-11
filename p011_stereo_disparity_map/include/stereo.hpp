#pragma once

#include "Eigen/Core"
#include "commons.hpp"
#include <opencv2/opencv.hpp>

namespace stereo {
typedef struct _camera_info_t {
  double fx; // focal length x-direction
  double fy; // focal length y-direction
  double cx; // camera center x
  double cy; // camera center y
} camera_intrinsics_t;

typedef struct _stereo_camera_t {
  camera_intrinsics_t left;
  camera_intrinsics_t right;
  double baseline;
} stereo_camera_intrinsics_t;

void getPointCloudFromStereoImagePair(
    const char *left_image_path, const char *right_image_path,
    const stereo_camera_intrinsics_t &camera_intrinsics,
    std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
        &pointcloud);

} // namespace stereo
