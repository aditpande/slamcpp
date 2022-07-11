#ifndef COMMONS_HPP
#define COMMONS_HPP

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#define usleep(usec)                                                           \
  std::this_thread::sleep_for(std::chrono::microseconds(usec))

#endif // COMMONS_HPP
