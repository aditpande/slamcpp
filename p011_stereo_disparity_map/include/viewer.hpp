#pragma once
#include "commons.hpp"
#include "viewer.hpp"
#include <Eigen/Core>
#include <pangolin/pangolin.h>

namespace viewer {
void showPointCloud(
    const std::vector<Eigen::Vector4d,
                      Eigen::aligned_allocator<Eigen::Vector4d>> &pointcloud);
}
