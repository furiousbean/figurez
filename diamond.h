#ifndef DIAMOND_H
#define DIAMOND_H

#include "figure.h"
#include <QtGui>

class Diamond : public Figure {
private:
    void show();
public:
    Diamond(QPixmap *ncanvas, int nXpos, int nYpos);
    ~Diamond();
    void match_pattern(int ** pattern);
};

#endif //DIAMOND_H