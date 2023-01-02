#include "player.h"
#include "game.h"

const unsigned Player::delta = 0x0039F4;

Player::Player(unsigned int id, const char *const name) :
        ID(id),
        name(name) {
    if (id < 1 || id > 8) {
        throw std::invalid_argument("invalid player ID");
    }

    // TODO
    for (auto x : Unit::names) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * 0xFA;
        resources2.emplace_back(x.name, address);
    }
    Printable<>::new_row(2);
    for (auto x : Unit::overview) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
    Printable<>::new_column(22);
    for (auto x : Unit::material) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
    Printable<>::new_column(22);
    for (auto x : Unit::food) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
    Printable<>::new_column(22);
    for (auto x : Unit::weapons) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
    Printable<>::new_column(22);
    for (auto x : Unit::troops) {
        void *address = (char *) Game::get_instance()->BASE_ADDRESS + x.offset + (ID-1) * Player::delta;
        resources.emplace_back(x.name, address);
    }
}

void Player::update() {

    for (auto &res : resources) {
        res.reprint();
    }
    for (auto &res : resources2) {
        res.reprint();
    }
}
