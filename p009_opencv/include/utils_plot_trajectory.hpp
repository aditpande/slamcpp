#pragma once

#include "commons.hpp"

#include <pangolin/pangolin.h>
#include <Eigen/Core>
#include <Eigen/Geometry>

#include "sophus/se3.hpp"

typedef std::vector<Sophus::SE3d, Eigen::aligned_allocator<Sophus::SE3d>> TrajectoryType;

/**
 * @brief Reads the trajectory data from file and returns it.
 *
 * @param filepath Path to file that contains the trajectory data
 * @return TrajectoryType
 */

TrajectoryType ReadTrajectory(const std::string &filepath);

void DrawTrajectory(const TrajectoryType &traj);

void DrawTrajectory(const TrajectoryType &true_traj, const TrajectoryType &noisy_traj);

/**
 * @brief plot line using the points from trajectory in Pangolin window
 *
 * @param traj          Trajectory to plot
 * @param linewidth     Width of line to plot
 * @param line_red      Line color (red)
 * @param line_green    Line color (red)
 * @param line_blue     Line color (red)
 */
void PlotLineWithPointsFromTrajectory(
  const TrajectoryType &traj,
  const float &linewidth,
  const float &line_red,
  const float &line_green,
  const float &line_blue
);
