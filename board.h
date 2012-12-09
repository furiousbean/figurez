#ifndef BOARD_H
#define BOARD_H

#include <QtGui>
#include "figure.h"
#include "const.h"
class Board {
private:
    Figure* field[W][H];
    QPixmap *canvas;
    int delta;
    void remove_figs(int Xpos, int Ypos);
    void rec_check(int ** markField, int Xpos, int Ypos);
public:
    Board(QPixmap *pixmap);
    ~Board();
    int have_something(int Xpos, int Ypos);
    void draw_selection(int Xpos, int Ypos);
    void remove_selection(int Xpos, int Ypos);
    int move(int Xold, int Yold, int Xnew, int Ynew);
    void insert_new();
    int get_delta();
};

#endif //BOARD_H
