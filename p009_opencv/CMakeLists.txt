cmake_minimum_required(VERSION 3.10)

project(p008_sophus_pangolin VERSION 1.0)

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BUILD_TYPE "Debug")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

find_package(Eigen3 REQUIRED)
message("Eigen3_FOUND: ${Eigen3_FOUND}")
message("EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")

find_package(fmt REQUIRED)
message("fmt_FOUND: ${fmt_FOUND}")
message("fmt_DIR: ${fmt_DIR}")
message("FMT_LIBRARIES: ${FMT_LIBRARIES}")
message("FMT_INCLUDE_DIR: ${FMT_INCLUDE_DIR}")

find_package(Pangolin REQUIRED)
message("Pangolin_FOUND: ${Pangolin_FOUND}")
message("Pangolin_DIR: ${Pangolin_DIR}")
message("Pangolin_LIBRARIES: ${Pangolin_LIBRARIES}")

# build executable: Vizualize Geometry
add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${Pangolin_LIBRARIES}
    fmt
)

target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${Eigen3_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/thirdparty/Sophus
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/utils_plot_trajectory.cpp
)
