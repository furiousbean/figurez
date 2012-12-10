#include <QtGui>
#include "const.h"
#include "output_widget.h"

void OutputWidget::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.drawImage(0,0, canvas -> toImage());
}

void OutputWidget::mousePressEvent(QMouseEvent* event) {
    int x = event -> x();
    int y = event -> y();
    int Xpos = (x - LineWidth) / (CellWidth + LineWidth);
    int Ypos = (y - LineWidth) / (CellHeight + LineWidth);
    emit fieldPressed(Xpos, Ypos);
}

OutputWidget::OutputWidget(QPixmap* pixmap) {
    canvas = pixmap;
}