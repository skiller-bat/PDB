#include <iostream>

#include "player.h"

const unsigned Player::delta = 0x0039F4;

Player::Player(unsigned int id, const char *const name) :
        ID(id),
        name(name) {
    if (id < 1 || id > 8) {
        throw std::invalid_argument("invalid player ID");
    }
}

void Player::update() {

    for (auto &res : resources) {
        std::int32_t data = res.get(this);
        std::cout << res.name << ": " << data << std::endl;
    }
}
