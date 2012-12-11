#ifndef VLINE_H
#define VLINE_H

#include "figure.h"
#include <QPixmap>

class Vline : public Figure {
private:
    virtual void show();
public:
    Vline(QPixmap *ncanvas, int nXpos, int nYpos);
    virtual void match_pattern(int ** pattern);
};

#endif //VLINE_H
