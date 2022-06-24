cmake_minimum_required(VERSION 3.10)

project(Hello)

add_executable(hello)
target_sources(hello PRIVATE
    src/hello.cpp
)
