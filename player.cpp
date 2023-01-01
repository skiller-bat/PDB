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
        // what is auto here?
//        auto data = res.get(this);
//        auto data = res.get();
//        std::cout << res.name << ": " << data << std::endl;
        res.update();
    }
}
