#include <curses.h>
#include "printable.h"


template class Printable<uint32_t>;


template<typename DataType>
Printable<DataType>::Printable(Window window) : window(window)
    {}

template<typename DataType>
void Printable<DataType>::update() {

    mvprintw(window.row, window.col, "%d", get());
}
