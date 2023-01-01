#ifndef PDB_PRINTABLE_H
#define PDB_PRINTABLE_H


#include <cstdint>
#include "window.h"

template<typename DataType=std::uint32_t>
class Printable {

public:
    const Window window;

    Printable(Window window);

    void update();

    virtual DataType get() = 0;
};


#endif //PDB_PRINTABLE_H
