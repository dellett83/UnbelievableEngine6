cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(UNBELIEVABLEENGINE6)

include_directories(
	src
)

add_library(UnbelievableEngine6
	src/UnbelievableEngine6/UnbelievableEngine6.h
	src/UnbelievableEngine6/Core.cpp 
	src/UnbelievableEngine6/Core.h
	src/UnbelievableEngine6/Entity.h
	src/UnbelievableEngine6/Entity.cpp
	src/UnbelievableEngine6/Component.h
	src/UnbelievableEngine6/Component.cpp

)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo UnbelievableEngine6)