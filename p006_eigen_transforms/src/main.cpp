#include "Eigen/Core"
#include "Eigen/Geometry" // includes the geometry related API
#include "commons.hpp"
// #include "sophus/geometry.hpp"

int main(int argc, char **argv) {
  Eigen::Quaterniond q1(0.63, -0.41, 0.56, 0.09);
  q1.normalize();
  Eigen::Vector3d t1(0.4, 0.2, -0.5);
  Eigen::Isometry3d T1w(q1);
  T1w.pretranslate(t1);

  Eigen::Quaterniond q2(0.61, -0.44, 0.21, 0.52);
  q2.normalize();
  Eigen::Vector3d t2(0.2, -0.45, 0.3);
  Eigen::Isometry3d T2w(q2);
  T2w.pretranslate(t2);

  Eigen::Vector3d p1(0.56, 0.01, 0.34);

  std::clock_t time_start = std::clock();

  Eigen::Vector3d p2 = T2w * T1w.inverse() * p1;

  std::clock_t time_end = std::clock();

  std::cout << "Coordinates of p in frame of Agent2: " << p2.transpose()
            << std::endl;

  std::cout << "Total time taken for this operation: "
            << (time_end - time_start) << " micro-seconds" << std::endl;

  return 0;
}
