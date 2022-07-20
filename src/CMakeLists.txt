cmake_minimum_required(VERSION 3.10)

find_package(pybind11 REQUIRED)

# set the project name
project(Pybind_Fftw3i)

add_executable(Main main.c)
target_link_libraries(Main PUBLIC fftw3 m)
target_include_directories(Main PUBLIC "${PROJECT_BINARY_DIR}")

pybind11_add_module(bindings MODULE bindings.cpp)
target_link_libraries(bindings PRIVATE fftw3 m)
target_include_directories(bindings PUBLIC "${PROJECT_BINARY_DIR}")


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

