#pragma once

#include <chrono>
#include <thread>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <pangolin/pangolin.h>


#define  usleep(usec)   std::this_thread::sleep_for(std::chrono::microseconds(usec))

void DrawTrajectory(
    std::vector<Eigen::Isometry3d, Eigen::aligned_allocator<Eigen::Isometry3d>>
);

