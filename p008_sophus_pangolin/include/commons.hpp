#pragma once

#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <thread>
#include <chrono>
#define  usleep(usec)   std::this_thread::sleep_for(std::chrono::microseconds(usec))