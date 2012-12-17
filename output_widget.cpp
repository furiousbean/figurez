#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>

#include "const.h"
#include "output_widget.h"

void OutputWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0,0, canvas -> toImage());
}

void OutputWidget::mousePressEvent(QMouseEvent* event) {
    int x = event -> x();
    int y = event -> y();
    int Xpos = (x - Gp -> get_LineWidth()) / (Gp -> get_CellWidth() + Gp -> get_LineWidth());
    int Ypos = (y - Gp -> get_LineWidth()) / (Gp -> get_CellHeight() + Gp -> get_LineWidth());
    emit fieldPressed(Xpos, Ypos);
}

OutputWidget::OutputWidget(QPixmap* pixmap, const GameParams &gp) {
    canvas = pixmap;
    Gp = &gp;
}