#ifndef HLINE_H
#define HLINE_H

#include "figure.h"
#include <QPixmap>

class Hline : public Figure {
private:
    virtual void show();
public:
    Hline(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Hline();
    virtual void match_pattern(int ** pattern);
};

#endif //HLINE_H