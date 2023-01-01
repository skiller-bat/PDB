#include <curses.h>
#include "printable.h"


template class Printable<uint32_t>;

template<> unsigned Printable<>::row = 0;
template<> unsigned Printable<>::col = 0;

template<typename DataType>
Printable<DataType>::Printable(const char *name) : Printable(name, {row, col + 10, 6})
    {}

template<typename DataType>
Printable<DataType>::Printable(const char *name, Window window) :
        name(name),
        window(window) {
    mvprintw(row, col, "%s:", name);
    row++;
    if (row >= 10)
        new_column(25);
}

template<typename DataType>
void Printable<DataType>::reprint() {

    window.clear();
    DataType old = get();
    DataType new_ = update_and_get();
    if (new_ > old) {
        color_set(1, 0);
    } else if (new_ < old) {
        color_set(2, 0);
    } else {
        color_set(3, 0);
    }
    mvprintw(window.row, window.col, "%6d", new_);
}

template<typename DataType>
void Printable<DataType>::new_column(unsigned col_delta) {
    row = 0;
    col += col_delta;
}
