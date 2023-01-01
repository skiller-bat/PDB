#ifndef PDB_UNIT_H
#define PDB_UNIT_H


#include <array>

class Unit {

public:
    const unsigned offset;
    const char *const name;
    // type: uint16, float32, ...

    Unit(const char *name, unsigned offset);

    static const std::array<Unit, 27> stuff;
};


#endif //PDB_UNIT_H
