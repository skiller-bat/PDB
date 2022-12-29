#ifndef PDB_GAME_H
#define PDB_GAME_H


#include <minwindef.h>

#define EXECUTABLE_NAME "Stronghold Crusader.exe"

class Game {

    static const Game *instance; // TODO: deallocate this object (to call deconstructor)
    Game(HANDLE handle, void *base);
    ~Game();

public:
    const HANDLE PROC_HANDLE;
    const void *const BASE_ADDRESS;

    static const Game *get_instance();
    static void win_api_error();
};


#endif //PDB_GAME_H
