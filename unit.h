#ifndef PDB_UNIT_H
#define PDB_UNIT_H


#include <array>

class Unit {

public:
    const unsigned offset;
    const char *const name;
    // type: uint16, float32, ...

    Unit(const char *name, unsigned offset);

    static const std::array<Unit, 9> overview;
    static const std::array<Unit, 4> material;
    static const std::array<Unit, 8> food;
    static const std::array<Unit, 8> weapons;
    static const std::array<Unit, 10> troops;
    static const std::array<Unit, 1> names;
};


#endif //PDB_UNIT_H
