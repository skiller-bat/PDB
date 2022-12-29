#include <iostream>

#include "player.h"

int main(int argc, char *argv[]) {

    if (argc != 2)
        return EXIT_FAILURE;
    if (argv[1][0] < '1' || argv[1][0] > '8')
        return EXIT_FAILURE;
    if (argv[1][1] != '\0')
        return EXIT_FAILURE;


    Player *p = new Player(argv[1][0] - '0', "MyName");
    p->update();

    return EXIT_SUCCESS;
}
