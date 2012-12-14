#include "figure.h"
#include "const.h"
#include "QPainter"

Figure::Figure(QPixmap *ncanvas, GameParams *gp, int nXpos, int nYpos) {
    canvas = ncanvas; Gp = gp;
    Xpos = nXpos; Ypos = nYpos;
}

void Figure::hide() {
    QPainter painter(canvas);
    painter.fillRect(QRect(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth(), 
        Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth(), 
        Gp -> get_CellWidth(), Gp -> get_CellHeight()),  Qt::white);
}

void Figure::select() {
    QPainter painter(canvas);
    painter.fillRect(QRect(Xpos * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth(), 
        Ypos * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth(), 
        Gp -> get_CellWidth(), Gp -> get_CellHeight()),  QColor(127, 199, 255, 255));

}

void Figure::draw_selection() {
    select();
    show();
}

void Figure::remove_selection() {
    hide();
    show();
}

void Figure::move(int nXpos, int nYpos) {
    hide();
    Xpos = nXpos; Ypos = nYpos;
    hide(); show();
}

Figure::~Figure() {
    hide();
}