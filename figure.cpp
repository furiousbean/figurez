#include "figure.h"
#include "const.h"

void Figure::hide() {
	QPainter painter(canvas);
	painter.fillRect(QRect(Xpos * (CellWidth + LineWidth) + LineWidth, 
		Ypos * (CellHeight + LineWidth) + LineWidth, 
		CellWidth, CellHeight),  Qt::white);
}

void Figure::select() {
	QPainter painter(canvas);
	painter.fillRect(QRect(Xpos * (CellWidth + LineWidth) + LineWidth, 
		Ypos * (CellHeight + LineWidth) + LineWidth, 
		CellWidth, CellHeight),  QColor(127, 199, 255, 255));

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

int Figure::get_type() {
	return type;
}

Figure::~Figure() {
	hide();
}