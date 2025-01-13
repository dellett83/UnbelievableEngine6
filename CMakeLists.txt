cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(UNBELIEVABLEENGINE6)

add_definitions(-DGLEW_STATIC)

include_directories(
	src
	contrib/include
	contrib/cl-windows-x86_64/include
)

link_directories(
	${PROJECT_SOURCE_DIR}/contrib/cl-windows-x86_64/lib
)

add_library(rend 
	src/rend/Mesh.cpp
	src/rend/Mesh.h
	src/rend/Model.h
	src/rend/RenderTexture.cpp
	src/rend/RenderTexture.h
	src/rend/Shader.cpp
	src/rend/Shader.h
	src/rend/Texture.cpp
	src/rend/Texture.h
	src/rend/Rend.h
)

target_link_libraries(rend glew32s SDL2 opengl32 openal32)

add_library(UnbelievableEngine6
	src/UnbelievableEngine6/UnbelievableEngine6.h
	src/UnbelievableEngine6/Core.h
	src/UnbelievableEngine6/Core.cpp 
	src/UnbelievableEngine6/Entity.h
	src/UnbelievableEngine6/Entity.cpp
	src/UnbelievableEngine6/Component.h
	src/UnbelievableEngine6/Component.cpp
	src/UnbelievableEngine6/Transform.h
	src/UnbelievableEngine6/Transform.cpp
	src/UnbelievableEngine6/TriangleRenderer.h
	src/UnbelievableEngine6/TriangleRenderer.cpp
	src/UnbelievableEngine6/Window.h
	src/UnbelievableEngine6/Window.cpp
	src/UnbelievableEngine6/Resource.h
	src/UnbelievableEngine6/Resource.cpp
	src/UnbelievableEngine6/Texture.h
	src/UnbelievableEngine6/Texture.cpp
	src/UnbelievableEngine6/Model.h
	src/UnbelievableEngine6/Model.cpp
	src/UnbelievableEngine6/Keyboard.h
	src/UnbelievableEngine6/Keyboard.cpp
	src/UnbelievableEngine6/Input.h
	src/UnbelievableEngine6/Input.cpp
	src/UnbelievableEngine6/Resources.h
	src/UnbelievableEngine6/Resources.cpp
	src/UnbelievableEngine6/ModelRenderer.h
	src/UnbelievableEngine6/ModelRenderer.cpp
	src/UnbelievableEngine6/Audio.h
	src/UnbelievableEngine6/Audio.cpp
	src/UnbelievableEngine6/AudioSource.h
	src/UnbelievableEngine6/AudioSource.cpp
	src/UnbelievableEngine6/Sound.h
	src/UnbelievableEngine6/Sound.cpp
	src/UnbelievableEngine6/stb_vorbis.c
)

target_link_libraries(UnbelievableEngine6 rend)

add_executable(demo
	src/demo/main.cpp
)

target_link_libraries(demo UnbelievableEngine6)