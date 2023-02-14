cmake_minimum_required(VERSION 3.16)

project(TVE-trash-visual-engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:"MSVCRT.lib")

if (WIN32)
	set(CMAKE_GENERATOR "Visual Studio 17 2022")
elseif (UNIX)
	set(CMAKE_GENERATOR "Ninja")
endif()

include(cmake/FindSpdlog.cmake)
include(cmake/FindGLFW.cmake)

include_directories(
	./src/)

add_subdirectory(./src)

add_executable(main main.cc)

target_link_libraries(main
	PUBLIC
	TVE)