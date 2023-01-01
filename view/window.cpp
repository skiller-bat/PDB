#include "window.h"

#include <curses.h>

Window::Window(unsigned row, unsigned col, unsigned len) :
        row(row), col(col), len(len)
    {}

void Window::clear() const {
    for (unsigned i = col; i < col + len; ++i) {
        mvaddch(row, i, ' ');
    }
}
