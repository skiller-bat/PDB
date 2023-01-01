#include "unit.h"

Unit::Unit(const char *name, unsigned int offset) : offset(offset), name(name)
    {}

const std::array<Unit, 27> Unit::stuff {
        Unit("Wood", 0xD5FCC4),
        Unit("Hops", 0xD5FCC8),
        Unit("Stone", 0xD5FCCC),
        Unit("?", 0xD5FCD0),
        Unit("Iron", 0xD5FCD4),
        Unit("Pitch", 0xD5FCD8),
        Unit("?", 0xD5FCDC),
        Unit("Wheat", 0xD5FCE0),
        Unit("Bread", 0xD5FCE4),
        Unit("Cheese", 0xD5FCE8),
        Unit("Meat", 0xD5FCEC),
        Unit("Apple", 0xD5FCF0),
        Unit("Beer", 0xD5FCF4),
        Unit("Gold", 0xD5FCF8),
        Unit("Flower", 0xD5FCFC),
        Unit("Arch", 0xD5FD00),
        Unit("Crossbow", 0xD5FD04),
        Unit("Spear", 0xD5FD08),
        Unit("Pike", 0xD5FD0C),
        Unit("Maze", 0xD5FD10),
        Unit("Sword", 0xD5FD14),
        Unit("Leather", 0xD5FD18),
        Unit("Armor", 0xD5FD1C),
        Unit("?", 0xD5FD20),
        Unit("?", 0xD5FD24),
        Unit("Troops", 0xD5FD28),
        Unit("?", 0xD5FD2C),
};
