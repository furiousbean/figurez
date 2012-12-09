#ifndef GAME_H
#define GAME_H

#include <QtGui>
#include "board.h"
#include "const.h"
class Game {
private:
    QPixmap *canvas;
    QStatusBar* infobar;
    QLabel *scorelabel;
    Board* board;
    int selected, Xsel, Ysel, score;
    void draw_grid();
    void update_score(int delta);
public:
    Game(QPixmap *pixmap, QStatusBar *statusbar, QLabel *label);
    ~Game();
    void push_field(int Xpos, int Ypos);
};

#endif //GAME_H
