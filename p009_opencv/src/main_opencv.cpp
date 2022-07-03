#include "basics.hpp"
#include "commons.hpp"
#include "undistortion.hpp"

using namespace std;

int main(int argc, char **argv) {

  char *filepath = argv[1];

  opencv_basics(filepath);

  calibrate_camera(filepath);

  return 0;
}
