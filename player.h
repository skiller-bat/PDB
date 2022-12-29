#ifndef PDB_PLAYER_H
#define PDB_PLAYER_H


#include <array>

#include "resource.h"

class Player {

    std::array<Resource, 31> resources {
        Resource("Wood", 0xD5FCC4),
        Resource("Hops", 0xD5FCC8),
        Resource("Stone", 0xD5FCCC),
        Resource("?", 0xD5FCD0),
        Resource("Iron", 0xD5FCD4),
        Resource("Pitch", 0xD5FCD8),
        Resource("?", 0xD5FCDC),
        Resource("Wheat", 0xD5FCE0),
        Resource("Bread", 0xD5FCE4),
        Resource("Cheese", 0xD5FCE8),
        Resource("Meat", 0xD5FCEC),
        Resource("Apple", 0xD5FCF0),
        Resource("Beer", 0xD5FCF4),
        Resource("Gold", 0xD5FCF8),
        Resource("Flower", 0xD5FCFC),
        Resource("Arch", 0xD5FD00),
        Resource("Crossbow", 0xD5FD04),
        Resource("Spear", 0xD5FD08),
        Resource("Pike", 0xD5FD0C),
        Resource("Maze", 0xD5FD10),
        Resource("Sword", 0xD5FD14),
        Resource("Leather", 0xD5FD18),
        Resource("Armor", 0xD5FD1C),
        Resource("?", 0xD5FD20),
        Resource("?", 0xD5FD24),
        Resource("Troops", 0xD5FD28),
        Resource("?", 0xD5FD2C),
        Resource("?", 0xD5FD30),
        Resource("?", 0xD5FD34),
        Resource("?", 0xD5FD38),
        Resource("?", 0xD5FD3C),
    };

public:
    const unsigned ID;
    const char * const name;

    static const unsigned delta;

    Player(unsigned id, const char *name);

    void update();
};


#endif //PDB_PLAYER_H
