#ifndef GAME_H
#define GAME_H

#include <QtGui>
#include "board.h"
#include "const.h"
class Game : public QObject {
Q_OBJECT
private:
    QPixmap *canvas;
    Board* board;
    int selected, Xsel, Ysel, score;
    void draw_grid();
    void update_score(int delta);
public:
    Game(QPixmap *pixmap);
    ~Game();
public slots:
    void reset();
    void push_field(int Xpos, int Ypos);
signals:
    void repaint();
    void moveFailed();
    void showScore(int);
};

#endif //GAME_H
