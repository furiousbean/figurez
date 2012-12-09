#ifndef VLINE_H
#define VLINE_H

#include "figure.h"
#include <QtGui>

class Vline : public Figure {
private:
    void show();
public:
    Vline(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Vline();
    void match_pattern(int ** pattern);
};

#endif //VLINE_H
