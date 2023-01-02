#ifndef PDB_PLAYER_H
#define PDB_PLAYER_H


#include <vector>

#include "resource.h"
#include "unit.h"

class Player {

    std::vector<Resource<>> resources;
    std::vector<Resource<std::array<char, 32>>> resources2;

public:
    const unsigned ID;
    const char * const name;

    static const unsigned delta;

    Player(unsigned id, const char *name);

    void update();
};


#endif //PDB_PLAYER_H
