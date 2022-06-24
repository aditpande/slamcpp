cmake_minimum_required(VERSION 3.10)
project(hello)

add_library(hello STATIC)

target_include_directories(hello
    PUBLIC
    include
)

target_sources(hello PRIVATE
    src/hello.cpp
)

set_target_properties(hello PROPERTIES
    PRIFIX lib
    OUTPUT_NAME hello
    SUFFIX ".a"
)
