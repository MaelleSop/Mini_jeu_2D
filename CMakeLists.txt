cmake_minimum_required(VERSION 3.10)
project(miniprojet)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets Multimedia REQUIRED)

include_directories(.)

file (GLOB_RECURSE CIR2_sceneview_src src/*.cpp src/*.h)

add_executable(miniprojet ${CIR2_sceneview_src})

target_link_libraries(miniprojet
        Qt6::Widgets
        Qt6::Multimedia)
