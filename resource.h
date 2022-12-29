#ifndef PDB_RESOURCE_H
#define PDB_RESOURCE_H


class Player;


class Resource {
    const unsigned offset;
    std::int32_t data; // TODO: support other types

public:
    const char *const name;

    Resource(const char *name, unsigned offset);

    /* performs update! */
    std::int32_t get(const Player *player);
};


#endif //PDB_RESOURCE_H
