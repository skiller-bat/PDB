#include <iostream>

#include <memoryapi.h>

#include "resource.h"
#include "player.h"
#include "game.h"


Resource::Resource(const char *const name, const unsigned offset) :
        name(name), offset(offset), data(0)
    {}

std::int32_t Resource::get(const Player *const player) {

    LPCVOID addr = (char *) Game::get_instance()->BASE_ADDRESS + offset + (player->ID - 1) * Player::delta;
    SIZE_T bytes_to_read = sizeof(std::int32_t); // TODO
    SIZE_T bytes_read;

    if (!ReadProcessMemory(Game::get_instance()->PROC_HANDLE, addr, &data, bytes_to_read, &bytes_read)
        || bytes_to_read != bytes_read) {
        Game::win_api_error();
    }

    return data;
}
