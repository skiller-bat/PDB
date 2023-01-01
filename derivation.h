#ifndef PDB_DERIVATION_H
#define PDB_DERIVATION_H


#include "view/printable.h"

template<typename DataType=std::uint32_t>
class Derivation: public Printable<> {

public:
    Derivation(Window window);

    DataType get() override;
};


#endif //PDB_DERIVATION_H
