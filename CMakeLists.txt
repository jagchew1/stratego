cmake_minimum_required(VERSION 3.25)
project(stratego_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(stratego_2 main.cpp board.cpp board.h piece.cpp piece.h piecetextures.cpp piecetextures.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(stratego_2 sfml-network sfml-window sfml-system sfml-audio sfml-graphics)