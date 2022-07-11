#pragma once

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#define usleep(usec)                                                           \
  std::this_thread::sleep_for(std::chrono::microseconds(usec))
