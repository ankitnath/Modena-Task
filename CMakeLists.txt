cmake_minimum_required(VERSION 3.00)
project(resize)
set(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )

include_directories(include ${OpenCV_INCLUDE_DIRS} )

add_library(Specs src/Specs.cpp)
add_library(utils src/utils.cpp)
add_library(imgedit src/imageEditing.cpp)

add_executable(demo demo/demo.cpp)

target_link_libraries(demo Specs imgedit utils ${OpenCV_LIBS})

