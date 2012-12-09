#ifndef HLINE_H
#define HLINE_H

#include "figure.h"
#include <QtGui>

class Hline : public Figure {
private:
    void show();
public:
    Hline(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Hline();
    void match_pattern(int ** pattern);
};

#endif //HLINE_H