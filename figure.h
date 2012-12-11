#ifndef FIGURE_H
#define FIGURE_H

class QPixmap;

class Figure {
protected:
    int type, Xpos, Ypos;
    QPixmap *canvas;
    virtual void show() = 0; //method which draw a figure
    void hide(); //hides figure
    void select(); // draw selection background

public:
    void draw_selection();
    void remove_selection();
    void move(int nXPos, int nYPos); //repaints figure in new position
    virtual void match_pattern(int ** pattern) = 0;
    int get_type(); //returns figure type
    ~Figure();
};

#endif //FIGURE_H
