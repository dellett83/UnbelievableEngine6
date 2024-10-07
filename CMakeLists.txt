cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(UNBELIEVABLEENGINE6)

include_directories(
	src
)

add_library(UnbelievableEngine6
	src/UnbelievableEngine6/dummy.cpp src/UnbelievableEngine6/dummy.h
)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo UnbelievableEngine6)