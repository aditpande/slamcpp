#include "basics.hpp"
#include "commons.hpp"

using namespace std;

int main(int argc, char **argv) {

  char *filepath = argv[1];
  opencv_basics(filepath);

  return 0;
}
