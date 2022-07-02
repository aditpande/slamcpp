cmake_minimum_required(VERSION 3.10)

project(p009_opencv VERSION 1.0)
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

# # ======================================================
# # May be needed for opencv build from source
# find_package(Iconv REQUIRED)
# message("Iconv_FOUND: ${Iconv_FOUND}")
# message("Iconv_LIBRARIES: ${Iconv_LIBRARIES}")
# set(OpenCV_DIR ./thirdparty/opencv/build)
# find_package(OpenCV REQUIRED PATHS ./thirdparty/opencv/build NO_DEFAULT_PATH)
# # ======================================================

find_package(OpenCV REQUIRED)
message("OpenCV_FOUND: ${OpenCV_FOUND}")
message("OpenCV_LIBRARIES: ${OpenCV_LIBRARIES}")
message("OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
message("OpenCV_LIBS: ${OpenCV_LIBS}")


# build executable: Vizualize Geometry
add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${Pangolin_LIBRARIES}
    fmt
    ${OpenCV_LIBRARIES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${Eigen3_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/thirdparty/Sophus
    ${OpenCV_INCLUDE_DIRS}
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
)
