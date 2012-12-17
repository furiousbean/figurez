#ifndef BOARD_H
#define BOARD_H

#include "figure.h"
#include "const.h"

class QPixmap;

/*!
 * Board implementation
 */

class Board {
private:
    Figure *** field;
    QPixmap *canvas;
    const GameParams *Gp;
    int delta;
    void remove_figs(int Xpos, int Ypos); /**< remove a figure connected with (Xpos, Ypos) cell */
    void rec_check(int ** markField, int Xpos, int Ypos); /**< recursive check for move ability */
public:
    Board(QPixmap &pixmap, const GameParams &gp); /**< initiates empty board */
    ~Board();
    int have_something(int Xpos, int Ypos) const; /**< check cell for having a figure */
    void draw_selection(int Xpos, int Ypos) const;
    void remove_selection(int Xpos, int Ypos) const;
    int move(int Xold, int Yold, int Xnew, int Ynew); /**< move figure in board from old to new position */
    void insert_new(); /**< adds new figures to board */
    int get_delta(); /**< returns score change */
};

#endif //BOARD_H
