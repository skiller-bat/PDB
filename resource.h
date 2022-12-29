#ifndef PDB_RESOURCE_H
#define PDB_RESOURCE_H


class Player;


template<typename DataType=std::uint32_t>
class Resource {
    const unsigned offset;
    DataType data;

public:
    const char *const name;

    Resource(const char *name, unsigned offset);

    /* performs update! */
    DataType get(const Player *player);
};


#endif //PDB_RESOURCE_H
