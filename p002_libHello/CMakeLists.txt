cmake_minimum_required(VERSION 3.10)

project(Using_Library VERSION 1.0)

set(CMAKE_BUILD_TYPE "Debug")

message("PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

# build library
add_subdirectory(mylibs)


# build executable
add_executable(use_libHello)

target_link_libraries(use_libHello PUBLIC
    hello
)

target_include_directories(use_libHello PUBLIC
    include
    ${PROJECT_SOURCE_DIR}/mylibs/hello/include
)

target_sources(use_libHello PRIVATE
    src/main.cpp
)
