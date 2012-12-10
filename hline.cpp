#include "figure.h"
#include "hline.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>

const int HLineSize = 5;

Hline::Hline(QPixmap *ncanvas, int nXpos, int nYpos) {
    canvas = ncanvas;
    Xpos = nXpos; Ypos = nYpos;
    type = 2;
    show();
}

void Hline::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(220, 20, 60, 255));
    painter.setPen(QPen(Qt::black, LineWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    painter.drawRect(QRect(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth / 8, 
        Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight * 3 / 8, 
        CellWidth * 3 / 4, CellHeight / 4));
}

void Hline::match_pattern(int ** pattern) {
    for (int j = 0; j < H; j++)
        for (int i = 0; i <= W - HLineSize; i++) {
            int passed = 1;
            for (int k = i; k < i + HLineSize; k++) passed = passed && pattern[k][j];
            if (passed) for (int k = i; k < i + HLineSize; k++) pattern[k][j] = -1;
        }
}
