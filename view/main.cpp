#include <iostream>
#include "printable.h"
#include "../player.h"
#include <curses.h>

void quit() {
    endwin();
}

int main(int argc, char *argv[]) {

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

    Player *p = new Player(1, "MyName");
    do {
        p->update();
        refresh();
    } while (getch() != 'x');

    return EXIT_SUCCESS;
}
