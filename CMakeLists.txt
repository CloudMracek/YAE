cmake_minimum_required(VERSION 3.1)

project(YAE)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS})

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

add_subdirectory(glfw)

if( MSVC ) 
	SET (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
endif()

set (SRC 
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
	)

find_package(GLEW REQUIRED)

add_executable( YAE WIN32 ${SRC})
target_link_libraries(YAE ${OPENGL_LIBRARIES} glfw GLEW::GLEW)
if (MSVC)
	if(${CMAKE_VERSION} VERSION_LESS "3.6.0")
		message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'GLFW-CMake-starter' as StartUp Project in Visual Studio.\n" )
    	else()
        	set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT GLFW-CMake-starter )
    	endif()
endif()
