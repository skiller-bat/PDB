#include <iostream>
#include "view/printable.h"
#include "player.h"
#include <curses.h>

void quit() {
    endwin();
}

int main(int argc, char *argv[]) {

    if (argc != 2)
        return EXIT_FAILURE;
    if (argv[1][0] < '1' || argv[1][0] > '8')
        return EXIT_FAILURE;
    if (argv[1][1] != '\0')
        return EXIT_FAILURE;

    initscr();
    atexit(quit);
    curs_set(0);

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    // make getch() non-blocking but waiting for 1 second
    // http://www.manpagez.com/man/3/curs_inopts/
    timeout(1000);

    Player *p = new Player(argv[1][0]-'0', "Player");
    do {
        p->update();
        refresh();
    } while (getch() != 'x');

    return EXIT_SUCCESS;
}
