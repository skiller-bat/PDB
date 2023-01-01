#include "derivation.h"


template class Derivation<uint32_t>;


template<typename DataType>
Derivation<DataType>::Derivation(Window window) : Printable(window)
    {}

template<typename DataType>
DataType Derivation<DataType>::get() {
    return 14;
}
