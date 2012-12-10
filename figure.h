#ifndef FIGURE_H
#define FIGURE_H

#include <QPixmap>
class Figure {
protected:
    int type, Xpos, Ypos;
    QPixmap *canvas;
    virtual void show() = 0;
    void hide();
    void select();

public:
    void draw_selection();
    void remove_selection();
    void move(int nXPos, int nYPos);
    virtual void match_pattern(int ** pattern) = 0;
    int get_type();
    ~Figure();
};

#endif //FIGURE_H
