#include "unit.h"

Unit::Unit(const char *name, unsigned int offset) : offset(offset), name(name)
    {}

const std::array<Unit, 9> Unit::overview {
        Unit("Gold", 0xD5FCF8),
        Unit("Troops", 0xD5FD28),
        Unit("Housing", 0xD5F860),
        Unit("Population", 0xD5F864),
        Unit("Fear Factor", 0xD61920), //
        Unit("Tax Level", 0xD61974), //
        Unit("Rations", 0xD61978), //
        Unit("Sentiment", 0xD5F84C),
        Unit("Strength", 0xD628E0),
};
const std::array<Unit, 4> Unit::material {
        Unit("Wood", 0xD5FCC4),
        Unit("Stone", 0xD5FCCC),
        Unit("Iron", 0xD5FCD4),
        Unit("Pitch", 0xD5FCD8),
};
const std::array<Unit, 8> Unit::food {
        Unit("Apple", 0xD5FCF0),
        Unit("Cheese", 0xD5FCE8),
        Unit("Meat", 0xD5FCEC),
        Unit("Bread", 0xD5FCE4),
        Unit("Flower", 0xD5FCFC),
        Unit("Wheat", 0xD5FCE0),
        Unit("Hops", 0xD5FCC8),
        Unit("Beer", 0xD5FCF4),
};
const std::array<Unit, 8> Unit::weapons {
        Unit("Arch", 0xD5FD00),
        Unit("Crossbow", 0xD5FD04),
        Unit("Spear", 0xD5FD08),
        Unit("Pike", 0xD5FD0C),
        Unit("Maze", 0xD5FD10),
        Unit("Sword", 0xD5FD14),
        Unit("Leather", 0xD5FD18),
        Unit("Armor", 0xD5FD1C),
};
const std::array<Unit, 10> Unit::troops {
        Unit("Archer", 0xD618A4),
        Unit("Crossbowman", 0xD618A8),
        Unit("Spearman", 0xD618AC),
        Unit("Pikeman", 0xD618B0),
        Unit("Mazeman", 0xD618B4),
        Unit("Swordsman", 0xD618B8),
        Unit("Knight", 0xD618BC),
        Unit("Ladderman", 0xD618C0),
        Unit("Engineer", 0xD618C4),
        Unit("Tunneler", 0xD618C8),
};
const std::array<Unit, 1> Unit::names {
        Unit("Player", 0x162347E),
};
