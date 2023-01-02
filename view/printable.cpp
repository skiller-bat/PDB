#include <curses.h>
#include <array>
#include "printable.h"


template class Printable<uint32_t>;
template class Printable<std::array<char, 32>>;

template<typename DataType> unsigned Printable<DataType>::row = 0;
template<typename DataType> unsigned Printable<DataType>::col = 0;

template<typename DataType>
Printable<DataType>::Printable(const char *name) : Printable(name, {row, col + 12, 5})
    {}

template<typename DataType>
Printable<DataType>::Printable(const char *name, Window window) :
        name(name),
        window(window) {
    mvprintw(row, col, "%s:", name);
    row++;
//    if (row >= 10)
//        new_column(22);
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

template<>
void Printable<std::array<char, 32>>::reprint() {

    window.clear();
    std::array<char, 32> new_ = update_and_get();
    char str[32]; // hacky
    for (int i = 0; i < 32; ++i) {
        str[i] = new_[i];
    }
    mvprintw(window.row, window.col, "%s", str);
}

template<typename DataType>
void Printable<DataType>::new_row(unsigned row_delta) {
    row += row_delta;
    col = 0;
}

template<typename DataType>
void Printable<DataType>::new_column(unsigned col_delta) {
    row = 2; // TODO: hacky
    col += col_delta;
}
