#include "basics.hpp"
#include "commons.hpp"

using namespace std;

void opencv_basics(const char *filepath) {
  cv::Mat image;
  image = cv::imread(filepath);

  if (image.data == nullptr) { // maybe the file does not exist
    cerr << "file" << filepath << " does not exist." << endl;
    return (void)0;
  }

  // print some basic information
  cout << "Image cols: " << image.cols << ", rows: " << image.rows
       << ", channels: " << image.channels() << endl;
  cv::imshow("image", image); // use cv::imshow to show the image
  cv::waitKey(0);             // display and wait for a keyboard input

  // check image type
  if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
    cout << "image type incorrect."
         << endl; // we need grayscale image or RGB image
    return (void)0;
  }

  // evaluate the time needed to iterate over the image [pixel by pixel]
  chrono::steady_clock::time_point t0 = chrono::steady_clock::now();
  for (std::size_t y = 0; y < image.rows; y++) {
    // use cv::Mat::ptr to get the pointer of each row
    // row_ptr is the pointer to y−th row
    unsigned char *row_ptr = image.ptr<unsigned char>(y);

    for (size_t x = 0; x < image.cols; x++) {
      // read the pixel on (x,y), x=column, y=row
      // data_ptr is the pointer to(x, y)
      unsigned char *data_ptr = &row_ptr[x * image.channels()];

      // visit the pixel in each channel
      for (int c = 0; c != image.channels(); c++) {
        // data should be pixel of I(x,y) in c-th channel
        unsigned char data = data_ptr[c];
      }
    }
  }
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();

  chrono::duration<double> time_used =
      chrono::duration_cast<chrono::duration<double>>(t1 - t0);
  cout << "time for iterating over each pixel in input image: "
       << time_used.count() << " seconds." << endl;

  // copying cv::Mat
  // NOTE: operator= will not copy the image data, but only the reference
  cv::Mat image_another = image;

  // changing image_another (reference) will also change image
  // set top-left 100∗100 block to zero
  image_another(cv::Rect(0, 0, 100, 100)).setTo(0);

  cv::imshow("original image", image);
  cv::waitKey(0);

  cv::Mat image_clone =
      image.clone(); // cv::Mat::clone - actually clone the data
  image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
  cv::imshow("image", image);
  cv::imshow("image_clone", image_clone);
  cv::waitKey(0);

  cv::destroyAllWindows();
}
