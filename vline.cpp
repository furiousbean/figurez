#include "figure.h"
#include "vline.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>

const int VLineSize = 5;

Vline::Vline(QPixmap *ncanvas, int nXpos, int nYpos) {
    canvas = ncanvas;
    Xpos = nXpos; Ypos = nYpos;
    type = 1;
    show();
}

void Vline::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(239, 211, 52, 255));
    painter.setPen(QPen(Qt::black, LineWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    painter.drawRect(QRect(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth * 3 / 8, 
        Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight / 8, 
        CellWidth / 4, CellHeight * 3 / 4));
}

void Vline::match_pattern(int ** pattern) {
    for (int i = 0; i < W; i++)
        for (int j = 0; j <= H - VLineSize; j++) {
            int passed = 1;
            for (int k = j; k < j + VLineSize; k++) passed = passed && pattern[i][k];
            if (passed) for (int k = j; k < j + VLineSize; k++) pattern[i][k] = -1;
        }
}
