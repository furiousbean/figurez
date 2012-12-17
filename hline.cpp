#include "figure.h"
#include "hline.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>

const int HLineSize = 5;

Hline::Hline(QPixmap &ncanvas, const GameParams &gp, int nXpos, int nYpos) : Figure(ncanvas, gp, nXpos, nYpos) { 
    show();
}


void Hline::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(220, 20, 60, 255));
    painter.setPen(QPen(Qt::black, Gp -> get_LineWidth(), Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    painter.drawRect(QRect(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() / 8, 
        Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() * 3 / 8, 
        Gp -> get_CellWidth() * 3 / 4, Gp -> get_CellHeight() / 4));
}

void Hline::match_pattern(int ** pattern) const {
    for (int j = 0; j < Gp -> get_H(); ++j)
        for (int i = 0; i <= Gp -> get_W() - HLineSize; ++i) {
            int passed = 1;
            for (int k = i; k < i + HLineSize; ++k) passed = passed && pattern[k][j];
            if (passed) for (int k = i; k < i + HLineSize; ++k) pattern[k][j] = -1;
        }
}

int Hline::get_type() const {
    return 2;
}