#include "undistortion.hpp"
#include "commons.hpp"

using namespace std;

void calibrate_camera(const char *filepath) {
  double k1 = -0.26509006, k2 = -0.0467439, p1 = 0.00183301, p2 = -0.00031471,
         k3 = 0.25231586;

  double fx = 536.07343019, fy = 536.01634475, cx = 342.37038791,
         cy = 235.53685635;

  cv::Mat image;
  image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);

  if (image.data == nullptr) { // maybe the file does not exist
    cerr << "file" << filepath << " does not exist." << endl;
    return (void)0;
  }

  int rows = image.rows, cols = image.cols;

  cv::Mat undistorted_image = cv::Mat(rows, cols, CV_8UC1);

  for (int v = 0; v < rows; v++) {
    for (int u = 0; u < cols; u++) {
      double x = (u - cx) / fx;
      double y = (v - cy) / fy;

      double r = sqrt(x * x + y * y);

      double x_distorted = x * (1 + k1 * r * r + k2 * r * r * r * r +
                                k3 * r * r * r * r * r * r) +
                           2 * p1 * x * y + p2 * (r * r + 2 * x * x);

      double y_distorted = y * (1 + k1 * r * r + k2 * r * r * r * r +
                                k3 * r * r * r * r * r * r) +
                           2 * p2 * x * y + p1 * (r * r + 2 * y * y);

      double u_distorted = x_distorted * fx + cx;
      double v_distorted = y_distorted * fy + cy;

      // check if the pixel is in the image boarder
      if (u_distorted >= 0 && v_distorted >= 0 && u_distorted < cols &&
          v_distorted < rows) {
        undistorted_image.at<uchar>(v, u) =
            image.at<uchar>((int)v_distorted, (int)u_distorted);
      } else {
        undistorted_image.at<uchar>(v, u) = 0;
      }
    }
  }

  cv::imshow("distorted", image);
  cv::imshow("undistorted", undistorted_image);
  cv::waitKey();
  cv::destroyAllWindows();
}
