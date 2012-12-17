#include "figure.h"
#include "diamond.h"
#include "const.h"
#include <QPixmap>
#include <QPainter>
#include <QPolygonF>

Diamond::Diamond(QPixmap &ncanvas, const GameParams &gp, int nXpos, int nYpos) : Figure(ncanvas, gp, nXpos, nYpos) {
    show();
}

void Diamond::show() {
    QPainter painter(canvas);
    QBrush brush(QColor(153, 17, 153, 255));
    painter.setPen(QPen(Qt::black, Gp -> get_LineWidth(), Qt::SolidLine, Qt::RoundCap,
        Qt::MiterJoin));
    painter.setBrush(brush);
    QPolygonF polygon;
    polygon << QPointF(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() / 2,
       Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() / 8);
    polygon << QPointF(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() / 8,
       Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() / 2);
    polygon << QPointF(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() / 2,
       Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() * 7 / 8);
    polygon << QPointF(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellWidth() * 7 / 8,
       Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth() / 2 + Gp -> get_CellHeight() / 2);
    painter.drawPolygon(polygon);
}

void Diamond::match_pattern(int ** pattern) const {
    for (int i = 1; i < Gp -> get_W() - 1; ++i)
        for (int j = 1; j < Gp -> get_H() - 1; ++j)
            if (pattern[i][j] && pattern[i + 1][j] && pattern[i - 1][j]  
                && pattern[i][j + 1] && pattern[i][j - 1]) {
                    pattern[i][j] = -1;
                    pattern[i + 1][j] = -1;
                    pattern[i - 1][j] = -1;
                    pattern[i][j + 1] = -1;
                    pattern[i][j - 1] = -1;
            }
}

int Diamond::get_type() const {
    return 3;
}