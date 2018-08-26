cmake_minimum_required(VERSION 3.1)

project(tinycolormap CXX)
set(CMAKE_CXX_STANDARD 11)

install(FILES ${CMAKE_SOURCE_DIR}/tinycolormap.hpp DESTINATION include)

option(TINYCOLORMAP_BUILD_TOOLS "Build tools" OFF)

if(TINYCOLORMAP_BUILD_TOOLS)
	# Append typical paths for Qt for macOS users
	if(APPLE AND EXISTS /usr/local/opt/qt5)
		list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt5")
	endif()
	if(APPLE AND EXISTS /usr/local/opt/qt)
		list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt")
	endif()

	add_subdirectory(tools/png-exporter)

	enable_testing()
	add_test(NAME png-exporter COMMAND $<TARGET_FILE:png-exporter> ${CMAKE_BINARY_DIR})
endif()
