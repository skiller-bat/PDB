#include "player.h"
#include "game.h"

const unsigned Player::delta = 0x0039F4;

Player::Player(unsigned int id, const char *const name) :
        ID(id),
        name(name) {
    if (id < 1 || id > 8) {
        throw std::invalid_argument("invalid player ID");
    }
    for (auto x : Unit::stuff) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
}

void Player::update() {

    for (auto &res : resources) {
        res.reprint();
    }
}
