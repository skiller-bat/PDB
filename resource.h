#ifndef PDB_RESOURCE_H
#define PDB_RESOURCE_H

#include "view/printable.h"

class Player;


template<typename DataType=std::uint32_t>
class Resource: public Printable<> {
    const void *const address;
    DataType data;

public:
    Resource(const char *name, const void *address);
    Resource(Window window, const char *name, const void *address);

    DataType get() override;
    DataType update_and_get() override;
};


#endif //PDB_RESOURCE_H
