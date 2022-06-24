#include "commons.hpp"
#include "Eigen/Core"
#include "Eigen/Dense"


int main(int argc, char **argv)
{
    Eigen::Matrix<float, 3, 2> mat_f32;

    mat_f32 = Eigen::MatrixXf::Zero(3, 2);
    std::cout << "mat_32:\n" << mat_f32 << std::endl;

    mat_f32 << 1, 2, 3, 4, 5, 6;
    std::cout << "mat_32:\n" << mat_f32 << std::endl;

    std::cout << "mat_32:\n";
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            std::cout << mat_f32(i, j) << "\t";
        }
        std::cout << std::endl;
    }


    Eigen::Vector3d v1_3d, v2_3d;
    v1_3d << 1, 2, 3;
    v2_3d << 4, 5, 6;

    std::cout << "v1_3d:" << std::endl;
    for (int i=0; i<3; i++){
        std::cout << v1_3d(i) << "\t";
    }
    std::cout << std::endl;

    std::cout<< "v2_3d: " << v2_3d.transpose() << std::endl;

    double x = v1_3d.dot(v2_3d);
    std::cout << "v1_3d.dot(v2_32) = " << x << std::endl;

    Eigen::Vector2d _temp_2d = mat_f32.transpose().cast<double>() * v1_3d;
    std::cout << "mat_f32.T * v1_3d:" << std::endl;
    std::cout << v1_3d.transpose() << std::endl;

    Eigen::Matrix3d _m = Eigen::Matrix3d::Random();
    std::cout << "_m:\n" << _m << std::endl;
    std::cout << "_m.transpose():\n" << _m.transpose() << std::endl;
    std::cout << "_m.inverse(): \n" << _m.inverse() << std::endl;
    std::cout << "_m.norm(): " << _m.norm() << std::endl;
    std::cout << "_m.determinant(): " << _m.determinant() << std::endl;

    Eigen::MatrixXd _M = Eigen::MatrixXd::Random(10, 10);
    std::cout << "matrix _M: \n" << _M << std::endl;
    Eigen::EigenSolver<Eigen::MatrixXd> es(_M);
    std::cout << "eigen values of _M:\n" << es.eigenvalues() << std::endl;
    std::cout << "eigen values of _M:\n" << es.eigenvectors() << std::endl;


    // solving equation Ax=y; find x?
    Eigen::Matrix<double, 10, 10> _A_tmp = Eigen::MatrixXd::Random(10, 10);
    Eigen::Matrix<double, 10, 10> _A = _A_tmp + _A_tmp.transpose();
    std::cout << "_A:\n" << _A << std::endl;

    Eigen::VectorXd _y = Eigen::VectorXd::Random(10);
    std::cout << "_y:\n" << _y.transpose() << std::endl;

    std::clock_t time_start = std::clock();
    Eigen::VectorXd _x = _A.inverse() * _y;
    std::cout << "time for solution: " << 1000 * (std::clock() - time_start)/ CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout << "_x:\n" << _x.transpose() << std::endl;

    // matrix decomposition
    time_start = std::clock();
    _x = _A.colPivHouseholderQr().solve(_y);
    std::cout << "time for solution using QR: " << 1000 * (std::clock() - time_start)/ CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout << "_x:\n" << _x.transpose() << std::endl;

    return 0;
}
