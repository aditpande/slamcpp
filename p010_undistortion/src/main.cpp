#include "commons.hpp"
#include "undistortion.hpp"

using namespace std;

int main(int argc, char **argv) {

  char *filepath = argv[1];

  calibrate_camera(filepath);

  return 0;
}
