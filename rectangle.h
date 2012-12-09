#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <QtGui>

class Rectangle : public Figure {
private:
    void show();
public:
    Rectangle(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Rectangle();
    void match_pattern(int ** pattern);
};

#endif //RECTANGLE_H