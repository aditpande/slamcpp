#include "Eigen/Core"
#include "commons.hpp"
#include "sophus/geometry.hpp"

int main(int argc, char **argv) {
  Eigen::Matrix<float, 3, 2> mat_f32;
  mat_f32 = Eigen::MatrixXf::Zero(3, 2);
  mat_f32 << 1, 2, 3, 4, 5, 6;
  std::cout << "mat_32:\n" << mat_f32 << std::endl;

  Eigen::Vector3d v1_3d;
  v1_3d << 1, 2, 3;
  std::cout << "v1_3d:\n" << v1_3d.transpose() << std::endl;

  const double kPi = Sophus::Constants<double>::pi();
  Sophus::SO3d Rx = Sophus::SO3d::rotX(kPi / 4); // rotations around x axes
  std::cout << "Rx.matrix():\n" << Rx.matrix() << std::endl;

  Sophus::SO3d Ry = Sophus::SO3d::rotY(kPi / 6); // rotations around y axes
  std::cout << "Ry.matrix():\n" << Ry.matrix() << std::endl;

  Sophus::SO3d Rz = Sophus::SO3d::rotZ(-kPi / 3); // rotations around y axes
  std::cout << "Rz.matrix():\n" << Rz.matrix() << std::endl;

  std::cout << "Rx*Ry*Rz:\n" << (Rx * Ry * Rz).matrix() << std::endl;
  std::cout << std::endl;

  // Rotation matrices can act on vectors
  Eigen::Vector3d vec;
  vec << 0.0, 0.0, 1.0;
  std::cout << "vec:\n" << vec << std::endl;
  std::cout << "Ry*vec\n" << Ry * vec << std::endl;
  std::cout << "Rx*(Ry*vec)\n" << Rx * (Ry * vec) << std::endl;
  std::cout << "(Rx*Ry)*vec\n" << (Rx * Ry) * vec << std::endl;
  std::cout << std::endl;

  // SO(3) are internally represented as unit quaternions.
  // Note that the order of coefficients of Eigen's quaternion class is
  // (imag0, imag1, imag2, real)
  std::cout << "Rx.matrix():\n" << Rx.matrix() << std::endl;
  std::cout << "Rx.unit_quaternion().coeffs(): (imaginary0, imaginary1, "
               "imaginary2, real):\n"
            << Rx.unit_quaternion().coeffs() << std::endl;
  std::cout << std::endl;
}
