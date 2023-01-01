#include <memoryapi.h>

#include "resource.h"
#include "game.h"


// declaration of all Rescource<DataType> instantiations
//template class Resource<uint16_t>; // problem?!
template class Resource<uint32_t>;



template<typename DataType>
Resource<DataType>::Resource(const char *name, const void *address) :
        Printable(name),
        address(address), data(0)
    {}

template<typename DataType>
Resource<DataType>::Resource(Window window, const char *const name, const void *address) :
        Printable(name, window),
        address(address), data(0)
    {}

template<typename DataType>
DataType Resource<DataType>::get() {
    return data;
}

template<typename DataType>
DataType Resource<DataType>::update_and_get() {

    SIZE_T bytes_to_read = sizeof(data);
    SIZE_T bytes_read;

    if (!ReadProcessMemory(Game::get_instance()->PROC_HANDLE, address, &data, bytes_to_read, &bytes_read)
        || bytes_to_read != bytes_read) {
        Game::win_api_error();
    }

    return data;
}
