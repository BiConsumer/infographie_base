cmake_minimum_required(VERSION 3.20)
project(infographie_base LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Third party includes
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/glfw)

set(GLAD_SOURCES_DIR "${PROJECT_SOURCE_DIR}/thirdparty/glad")
add_subdirectory("${GLAD_SOURCES_DIR}/cmake")
glad_add_library(glad_gl STATIC API gl:core=3.3)

# Project exec
add_executable(info_exec 
	src/main.cpp
	src/file_utils.hpp
	src/shader_utils.hpp
)

# Third party links
target_link_libraries(info_exec PRIVATE 
	glm::glm
	glfw
	glad_gl
)
