cmake_minimum_required(VERSION 3.19)
project(PDB)

set(CMAKE_CXX_STANDARD 14)

add_executable(PDB main.cpp player.cpp player.h game.cpp game.h resource.cpp resource.h)
target_link_libraries(PDB psapi)
