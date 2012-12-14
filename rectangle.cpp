#include "figure.h"
#include "rectangle.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>

Rectangle::Rectangle(QPixmap *ncanvas, GameParams *gp, int nXpos, int nYpos) : Figure(ncanvas, gp, nXpos, nYpos) {
    show();
}


void Rectangle::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(0, 168, 107, 255));
    painter.setPen(QPen(Qt::black, Gp -> get_LineWidth(), Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    painter.drawRect(QRect(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() / 4, 
        Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() / 4, 
        Gp -> get_CellWidth() / 2, Gp -> get_CellHeight() / 2));
}

void Rectangle::match_pattern(int ** pattern) {
    for (int i = 0; i < Gp -> get_W() - 1; ++i)
        for (int j = 0; j < Gp -> get_H() - 1; ++j)
            if (pattern[i][j] && pattern[i + 1][j] && pattern[i][j + 1]  && pattern[i + 1][j + 1]) {
                pattern[i][j] = -1;
                pattern[i + 1][j] = -1;
                pattern[i][j + 1] = -1;
                pattern[i + 1][j + 1] = -1;
            }
}

int Rectangle::get_type() const {
    return 0;
}