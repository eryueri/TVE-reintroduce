add_library(TVE 
	Core/Application.cc
	Core/Log.cc
	Events/Event.cc
	Events/KeyEvents.cc
	Events/WindowEvents.cc
	Window/WIN32Window.cc)

target_link_libraries(TVE
	PRIVATE
	spdlog
	glfw3)

set(PCH_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/pch.hh")

target_precompile_headers(TVE
	PRIVATE
	${PCH_HEADER})