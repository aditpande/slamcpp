#pragma once

#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <chrono>
#include <thread>
#define usleep(usec)                                                           \
  std::this_thread::sleep_for(std::chrono::microseconds(usec))

#include <Eigen/Core>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>