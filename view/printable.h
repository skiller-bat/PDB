#ifndef PDB_PRINTABLE_H
#define PDB_PRINTABLE_H


#include <cstdint>
#include "window.h"

template<typename DataType=std::uint32_t>
class Printable {

    static unsigned row;
    static unsigned col;

public:
    const char *const name;
    const Window window;

    Printable(const char *name);
    Printable(const char *name, Window window);

    void reprint();

    static void new_column(unsigned col_delta);

    virtual DataType get() = 0;
    virtual DataType update_and_get() = 0;
};


#endif //PDB_PRINTABLE_H
