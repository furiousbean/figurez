#include "figure.h"
#include "vline.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>

const int VLineSize = 5;

Vline::Vline(QPixmap *ncanvas, GameParams *gp, int nXpos, int nYpos) : Figure(ncanvas, gp, nXpos, nYpos) { 
    show();
}

void Vline::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(239, 211, 52, 255));
    painter.setPen(QPen(Qt::black, Gp -> get_LineWidth(), Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    painter.drawRect(QRect(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() * 3 / 8, 
        Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() / 8, 
        Gp -> get_CellWidth() / 4, Gp -> get_CellHeight() * 3 / 4));
}

void Vline::match_pattern(int ** pattern) {
    for (int i = 0; i < Gp -> get_W(); ++i)
        for (int j = 0; j <= Gp -> get_H() - VLineSize; ++j) {
            int passed = 1;
            for (int k = j; k < j + VLineSize; ++k) passed = passed && pattern[i][k];
            if (passed) for (int k = j; k < j + VLineSize; ++k) pattern[i][k] = -1;
        }
}

int Vline::get_type() const {
    return 1;
}