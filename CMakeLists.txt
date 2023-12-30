cmake_minimum_required(VERSION 3.5.0)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")

project(smolfuzz)

add_executable(smollfuzz_test
    ${PROJECT_SOURCE_DIR}/arg.c
    ${PROJECT_SOURCE_DIR}/call.c
    ${PROJECT_SOURCE_DIR}/ret.c

    ${PROJECT_SOURCE_DIR}/test.c
)