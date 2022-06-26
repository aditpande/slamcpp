cmake_minimum_required(VERSION 3.10)

project(p004_sophus VERSION 1.0)

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BUILD_TYPE "Debug")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

find_package(Eigen3 REQUIRED)
message("EIGEN3_FOUND: ${EIGEN3_FOUND}")
message("EIGEN3_INCLUDE_DIR: ${EIGEN3_INCLUDE_DIR}")

find_package(fmt REQUIRED)          # dependency for using sophus
message("FMT_FOUND: ${FMT_FOUND}")  # NOTE: fmt_FOUND does not seem to be defined even though the package config was found

add_subdirectory(thirdparty/Sophus)
# build executable
add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    fmt
)

target_include_directories(${PROJECT_NAME} PUBLIC
    include
    ${EIGEN3_INCLUDE_DIR}
    ${PROJECT_SOURCE_DIR}/thirdparty/Sophus     # sophus is header only
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
)
