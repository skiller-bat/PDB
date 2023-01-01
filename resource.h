#ifndef PDB_RESOURCE_H
#define PDB_RESOURCE_H

#include "view/printable.h"

class Player;


template<typename DataType=std::uint32_t>
class Resource: public Printable<> {
    const unsigned offset;
    DataType data;

public:
    const char *const name;

    Resource(Window window, const char *name, unsigned offset);

    /* performs update! */
    DataType get() override;
};


#endif //PDB_RESOURCE_H
