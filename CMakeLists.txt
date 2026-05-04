cmake_minimum_required(VERSION 3.15)
project(simple_pybind11_multiplier_test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(pybind11 CONFIG REQUIRED)

pybind11_add_module(simple_pybind11_multiplier_test src/bindings.cpp)

install(TARGETS simple_pybind11_multiplier_test DESTINATION .)
