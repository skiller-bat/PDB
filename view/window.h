#ifndef PDB_WINDOW_H
#define PDB_WINDOW_H


class Window {

public:
    const unsigned row;
    const unsigned col;
    const unsigned len;

    Window(unsigned row, unsigned col, unsigned len);
};


#endif //PDB_WINDOW_H
