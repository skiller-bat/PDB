#include <iostream>

#include <memoryapi.h>

#include "resource.h"
#include "player.h"
#include "game.h"


// declaration of all Rescource<DataType> instantiations
template class Resource<uint16_t>;
template class Resource<uint32_t>;


template<typename DataType>
Resource<DataType>::Resource(const char *const name, const unsigned offset) :
        name(name), offset(offset), data(0)
    {}

template<typename DataType>
DataType Resource<DataType>::get(const Player *const player) {

    LPCVOID addr = (char *) Game::get_instance()->BASE_ADDRESS + offset + (player->ID - 1) * Player::delta;
    SIZE_T bytes_to_read = sizeof(data);
//    std::cout << sizeof(data) << std::endl;
    SIZE_T bytes_read;

    if (!ReadProcessMemory(Game::get_instance()->PROC_HANDLE, addr, &data, bytes_to_read, &bytes_read)
        || bytes_to_read != bytes_read) {
        Game::win_api_error();
    }

    return data;
}
