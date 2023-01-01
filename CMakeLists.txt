cmake_minimum_required(VERSION 3.19)
project(PDB)

set(CMAKE_CXX_STANDARD 14)


include_directories(ncurses/include/ncursesw)
link_directories(ncurses/bin ncurses/lib)


add_executable(PDB main.cpp player.cpp player.h game.cpp game.h resource.cpp resource.h derivation.cpp derivation.h view/printable.cpp view/printable.h)
target_link_libraries(PDB psapi)

add_executable(Wiese view/main.cpp derivation.cpp derivation.h view/printable.cpp view/printable.h)

add_executable(View view/main.cpp player.cpp player.h game.cpp game.h resource.cpp resource.h derivation.cpp derivation.h view/printable.cpp view/printable.h view/window.cpp view/window.h resource.cpp resource.h)
target_link_libraries(View ncursesw6 ncursesw)
target_link_libraries(View psapi)
