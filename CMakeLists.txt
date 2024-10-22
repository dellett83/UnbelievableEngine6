cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(UNBELIEVABLEENGINE6)

include_directories(
	src
	contrib/include
	contrib/cl-windows-x86_64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/cl-windows-x86_64/lib
)

add_library(UnbelievableEngine6
	src/UnbelievableEngine6/UnbelievableEngine6.h
	src/UnbelievableEngine6/Core.cpp 
	src/UnbelievableEngine6/Core.h
	src/UnbelievableEngine6/Entity.h
	src/UnbelievableEngine6/Entity.cpp
	src/UnbelievableEngine6/Component.h
	src/UnbelievableEngine6/Component.cpp

	src/UnbelievableEngine6/main.cpp
	src/UnbelievableEngine6/Mesh.cpp
	src/UnbelievableEngine6/Mesh.h
	src/UnbelievableEngine6/Model.h
	src/UnbelievableEngine6/RenderTexture.cpp
	src/UnbelievableEngine6/RenderTexture.h
	src/UnbelievableEngine6/Shader.cpp
	src/UnbelievableEngine6/Shader.h
	src/UnbelievableEngine6/Texture.cpp
	src/UnbelievableEngine6/Texture.h

)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo UnbelievableEngine6)