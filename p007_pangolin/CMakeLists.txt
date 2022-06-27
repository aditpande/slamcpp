cmake_minimum_required(VERSION 3.10)

project(p007_pangolin VERSION 1.0)

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BUILD_TYPE "Debug")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

find_package(Eigen3 REQUIRED)
message("Eigen3_FOUND: ${Eigen3_FOUND}")
message("EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")

find_package(Pangolin REQUIRED)
message("Pangolin_FOUND: ${Pangolin_FOUND}")
message("Pangolin_DIR: ${Pangolin_DIR}")
message("Pangolin_LIBRARIES: ${Pangolin_LIBRARIES}")

# Vizualize Geometry: build executable
add_executable(${PROJECT_NAME}_vizualize_geometry)

target_link_libraries(${PROJECT_NAME}_vizualize_geometry PUBLIC
    ${Pangolin_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}_vizualize_geometry PRIVATE
    include
    ${Eigen3_INCLUDE_DIR}
)

target_sources(${PROJECT_NAME}_vizualize_geometry PRIVATE
    src/main_vizualize_geometry.cpp
)


# build executable
add_executable(${PROJECT_NAME}_plot_trajectory)

target_link_libraries(${PROJECT_NAME}_plot_trajectory PUBLIC
    ${Pangolin_LIBRARIES}
)

target_include_directories(${PROJECT_NAME}_plot_trajectory PRIVATE
    include
    ${Eigen3_INCLUDE_DIR}
)

target_sources(${PROJECT_NAME}_plot_trajectory PRIVATE
    src/main_plot_trajectory.cpp
    src/plot_trajectory_utils.cpp
)
