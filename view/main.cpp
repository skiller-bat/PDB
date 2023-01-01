#include <iostream>
#include "printable.h"
#include "../derivation.h"
#include "window.h"
#include "../player.h"
#include <curses.h>

void quit() {
    endwin();
}

int main(int argc, char *argv[]) {

    initscr();
    atexit(quit);
    curs_set(0);


//    Window window = Window(0,1,2);
//    Printable<> *p = new Derivation<>(window);
//    auto data = p->get();
//    std::cout << data << std::endl;
//    p->update();


    Player *p = new Player(1, "MyName");
    while (getch() != 'x') {
        p->update();
        refresh();
    }

    return EXIT_SUCCESS;
}
