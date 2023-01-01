#include <iostream>

#include <memoryapi.h>

#include "resource.h"
#include "player.h"
#include "game.h"


// declaration of all Rescource<DataType> instantiations
//template class Resource<uint16_t>; // problem?!
template class Resource<uint32_t>;


// TODO: constructor which generates windows itself (probably Printable())
template<typename DataType>
Resource<DataType>::Resource(Window window, const char *const name, const unsigned offset) :
        Printable(window),
        name(name), offset(offset), data(0)
    {}

template<typename DataType>
DataType Resource<DataType>::get() {

//    LPCVOID addr = (char *) Game::get_instance()->BASE_ADDRESS + offset + (player->ID - 1) * Player::delta;
    LPCVOID addr = (char *) Game::get_instance()->BASE_ADDRESS + offset + (1 - 1) * Player::delta;
    SIZE_T bytes_to_read = sizeof(data);
//    std::cout << sizeof(data) << std::endl;
    SIZE_T bytes_read;

    if (!ReadProcessMemory(Game::get_instance()->PROC_HANDLE, addr, &data, bytes_to_read, &bytes_read)
        || bytes_to_read != bytes_read) {
        Game::win_api_error();
    }

    return data;
}
