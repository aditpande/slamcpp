#pragma once

#include "Eigen/Core"
#include "commons.hpp"
#include <opencv2/features2d.hpp>
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

/**
 * @brief Reads stereo image pairs from image files
 *
 * @param left_image_path Path to image from left camera of stereo pair
 * @param right_image_path Path to image from right camera of stereo pair
 * @param left_image  left image
 * @param right_image right image
 */
void readStereoImagePairFromFiles(const char *left_image_path,
                                  const char *right_image_path,
                                  cv::Mat &left_image, cv::Mat &right_image);

/**
 * @brief Calibrate stereo camera images
 *
 * @param left_image image from left camera of stereo pair
 * @param right_image image from right camera of stereo pair
 * @param left_rectified_img rectified left camera image
 * @param right_rectified_img rectified right camera image
 */
void uncalibratedStereoRectification(const cv::Mat &left_image,
                                     const cv::Mat &right_image,
                                     cv::Mat &left_rectified_img,
                                     cv::Mat &right_rectified_img);

/**
 * @brief Get point cloud from stereo image pair
 *
 * @param left_image image from left camera of stereo pair
 * @param right_image image from right camera of stereo pair
 * @param camera_intrinsics camera intrinsic parameters
 * @param pointcloud point clouds
 */
void getPointCloudFromStereoImagePair(
    const cv::Mat &left_image, const cv::Mat &right_image,
    const stereo::stereo_camera_intrinsics_t &camera_intrinsics,
    std::vector<Eigen::Vector4d, Eigen::aligned_allocator<Eigen::Vector4d>>
        &pointcloud);

} // namespace stereo
