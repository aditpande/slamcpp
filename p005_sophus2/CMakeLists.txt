cmake_minimum_required(VERSION 3.10)

project(p005_sophus2 VERSION 1.0)

message("PROJECT_NAME: ${PROJECT_NAME}")
message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_BUILD_TYPE "Debug")

message("CMAKE_INSTALL_PREFIX: ${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")

# build executable
add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    fmt
)


target_include_directories(${PROJECT_NAME} PRIVATE
    include
    ${PROJECT_SOURCE_DIR}/thirdparty/eigen3     # eigen is header only
    ${PROJECT_SOURCE_DIR}/thirdparty/Sophus     # sophus is header only
)

target_sources(${PROJECT_NAME} PRIVATE
    src/main.cpp
)
