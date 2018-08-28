find_package(Qt5 COMPONENTS Gui REQUIRED)

include_directories(${Qt5Gui_INCLUDE_DIRS})

file(GLOB files ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

add_executable(png-exporter ${files})
target_link_libraries(png-exporter Qt5::Gui tinycolormap)
