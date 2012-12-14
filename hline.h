#ifndef HLINE_H
#define HLINE_H

#include "figure.h"
#include <QPixmap>

class Hline : public Figure {
private:
    virtual void show();
public:
    Hline(QPixmap *ncanvas, GameParams *gp, int nXpos, int nYpos);
    virtual void match_pattern(int ** pattern);
    virtual int get_type() const;
};

#endif //HLINE_H