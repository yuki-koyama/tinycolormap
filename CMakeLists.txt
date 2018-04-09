cmake_minimum_required(VERSION 3.1)

project(tinycolormap)
set(CMAKE_CXX_STANDARD 11)

install(FILES ./include/tinycolormap.h DESTINATION include)

option(TINYCOLORMAP_BUILD_DEMOS "build demos" OFF)

if(TINYCOLORMAP_BUILD_DEMOS)
	add_subdirectory(demos/png-exporter)

	enable_testing()
	add_test(NAME png-exporter COMMAND $<TARGET_FILE:png-exporter> ${CMAKE_BINARY_DIR})
endif()