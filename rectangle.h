#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <QPixmap>

class Rectangle : public Figure {
private:
    virtual void show();
public:
    Rectangle(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Rectangle();
    virtual void match_pattern(int ** pattern);
};

#endif //RECTANGLE_H
