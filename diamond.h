#ifndef DIAMOND_H
#define DIAMOND_H

#include "figure.h"
#include <QPixmap>

class Diamond : public Figure {
private:
    virtual void show();
public:
    Diamond(QPixmap &ncanvas, const GameParams &gp, int nXpos, int nYpos);
    virtual void match_pattern(int ** pattern) const;
    virtual int get_type() const;
};

#endif //DIAMOND_H