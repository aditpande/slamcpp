cmake_minimum_required(VERSION 3.10)

project(eigen_example VERSION 1.0)

set(CMAKE_BUILD_TYPE "Debug")

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

# build library


# build executable
add_executable(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${PROJECT_SOURCE_DIR}/thirdparty/eigen-3.4.0        # Eigen is added as a external thirdparty library
    ${PROJECT_SOURCE_DIR}/thirdparty/eigen-3.4.0        # Eigen is added as a external thirdparty library
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
)
