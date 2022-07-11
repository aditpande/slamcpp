cmake_minimum_required(VERSION 3.10)

project(p011_stereo_disparity_map VERSION 1.0)
set(CMAKE_BUILD_TYPE "Debug")

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

find_package(Eigen3 REQUIRED)
message("Eigen3_FOUND: ${Eigen3_FOUND}")
message("EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")

find_package(fmt REQUIRED)
message("fmt_FOUND: ${fmt_FOUND}")
message("fmt_DIR: ${fmt_DIR}")

find_package(Pangolin REQUIRED)
message("Pangolin_FOUND: ${Pangolin_FOUND}")
message("Pangolin_DIR: ${Pangolin_DIR}")
message("Pangolin_LIBRARIES: ${Pangolin_LIBRARIES}")

find_package(OpenCV REQUIRED)
message("OpenCV_FOUND: ${OpenCV_FOUND}")
message("OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS: ${OpenCV_LIBS}")

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${Pangolin_LIBRARIES}
    fmt
    ${OpenCV_LIBS}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${Eigen3_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/stereo.cpp
    src/viewer.cpp
)
