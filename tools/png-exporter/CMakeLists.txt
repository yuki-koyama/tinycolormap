cmake_minimum_required(VERSION 3.1)

find_package(Eigen3 REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB files *.cpp *.h)

add_executable(png-exporter ${files})

target_link_libraries(png-exporter Qt5::Gui)
