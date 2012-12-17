#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <QPixmap>

class Rectangle : public Figure {
private:
    virtual void show();
public:
    Rectangle(QPixmap &ncanvas, const GameParams &gp, int nXpos, int nYpos);
    virtual void match_pattern(int ** pattern) const;
    virtual int get_type() const;
};

#endif //RECTANGLE_H
