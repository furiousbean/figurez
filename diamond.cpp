#include "figure.h"
#include "diamond.h"
#include "const.h"

Diamond::Diamond(QPixmap *ncanvas, int nXpos, int nYpos) {
    canvas = ncanvas;
    Xpos = nXpos; Ypos = nYpos;
    type = 3;
    show();
}

void Diamond::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(153, 17, 153, 255));
    painter.setPen(QPen(Qt::black, LineWidth, Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    QPolygonF polygon;
    polygon << QPointF(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth / 2, Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight / 8);
    polygon << QPointF(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth / 8, Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight / 2);
    polygon << QPointF(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth / 2, Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight * 7 / 8);
    polygon << QPointF(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth * 7 / 8, Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight / 2);
    painter.drawPolygon(polygon);
}

void Diamond::match_pattern(int ** pattern) {
    for (int i = 1; i < W - 1; i++)
        for (int j = 1; j < H - 1; j++)
            if (pattern[i][j] && pattern[i + 1][j] && pattern[i - 1][j]  
                && pattern[i][j + 1] && pattern[i][j - 1]) {
                    pattern[i][j] = -1;
                    pattern[i + 1][j] = -1;
                    pattern[i - 1][j] = -1;
                    pattern[i][j + 1] = -1;
                    pattern[i][j - 1] = -1;
            }
}
