find_package(Qt5 COMPONENTS Gui REQUIRED)

include_directories(${Qt5Gui_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

file(GLOB files *.cpp *.h)

add_executable(png-exporter ${files})

target_link_libraries(png-exporter Qt5::Gui)
