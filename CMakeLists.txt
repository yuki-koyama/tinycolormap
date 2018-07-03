cmake_minimum_required(VERSION 3.1)

project(tinycolormap CXX)
set(CMAKE_CXX_STANDARD 11)

install(FILES ${CMAKE_SOURCE_DIR}/tinycolormap.hpp DESTINATION include)

option(TINYCOLORMAP_BUILD_TOOLS "Build tools" OFF)

if(TINYCOLORMAP_BUILD_TOOLS)
	add_subdirectory(tools/png-exporter)

	enable_testing()
	add_test(NAME png-exporter COMMAND $<TARGET_FILE:png-exporter> ${CMAKE_BINARY_DIR})
endif()