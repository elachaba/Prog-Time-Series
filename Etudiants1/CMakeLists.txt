cmake_minimum_required(VERSION 3.10)

project(RegArchTest)

project(RegArchTest VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(RegArchTest.h.in RegArchTest.h)

add_subdirectory(Error)
add_subdirectory(VectorAndMatrix)
add_subdirectory(RegArchLib)
add_subdirectory(Tests)


