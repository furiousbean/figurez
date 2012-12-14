#ifndef GAME_H
#define GAME_H

#include <QPixmap>
#include "board.h"
#include "const.h"

/*!
 * Game logic implemetation
 */

class Game : public QObject {
Q_OBJECT
private:
    QPixmap *canvas;
    Board *board;
    GameParams *Gp;
    int selected, Xsel, Ysel, score;
    void draw_grid(); /**< Draw empty grid */
    void update_score(int delta); /**< Update score by delta */
public:
    Game(QPixmap *pixmap, GameParams *gp);
    ~Game();
    int get_score(); /**< Return current score */
public slots:
    void reset(); /**< Reset game */
    void push_field(int Xpos, int Ypos); /**< Receives a mouse click to game field */
signals:
    void repaint();
    void moveFailed();
    void showScore(int);
};

#endif //GAME_H
