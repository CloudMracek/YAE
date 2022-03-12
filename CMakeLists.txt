cmake_minimum_required (VERSION 3.1)
project (YAE)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# The main executable
add_executable(YAE
  	src/main.cpp
	src/engine/controls.cpp
	src/engine/gameobject.cpp
	src/engine/init.cpp
	src/engine/mesh.cpp
	src/engine/render.cpp
	src/engine/scene.cpp
	src/engine/shaderloader.cpp
	src/engine/texture.cpp
	src/engine/windowmanager.cpp
	src/game/gamemain.cpp
	src/main.h
	src/engine/controls.h
	src/engine/gameobject.h
	src/engine/init.h
	src/engine/mesh.h
	src/engine/render.h
	src/engine/scene.h
	src/engine/shaderloader.h
	src/engine/texture.h
	src/engine/windowmanager.h
	src/game/gamemain.h
)

set_property(TARGET YAE PROPERTY CXX_STANDARD 11)
target_compile_options(YAE PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(YAE
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

target_include_directories(YAE
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
)