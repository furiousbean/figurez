#include "figure.h"
#include "rectangle.h"
#include "const.h"

Rectangle::Rectangle(QPixmap *ncanvas, int nXpos, int nYpos) {
	canvas = ncanvas;
	Xpos = nXpos; Ypos = nYpos;
	type = 0;
	show();
}

void Rectangle::show() {
	QPainter painter(canvas);
	QBrush brush(QColor(0, 168, 107, 255));
	painter.setPen(QPen(Qt::black, LineWidth, Qt::SolidLine, Qt::RoundCap,
                    Qt::MiterJoin));
	painter.setBrush(brush);
	painter.drawRect(QRect(Xpos * (CellWidth + LineWidth) + LineWidth / 2 + CellWidth / 4, 
		Ypos * (CellHeight + LineWidth) + LineWidth / 2 + CellHeight / 4, 
		CellWidth / 2, CellHeight / 2));
}

void Rectangle::match_pattern(int ** pattern) {
	for (int i = 0; i < W - 1; i++)
	  for (int j = 0; j < H - 1; j++)
			if (pattern[i][j] && pattern[i + 1][j] && pattern[i][j + 1]  && pattern[i + 1][j + 1]) {
				pattern[i][j] = -1;
				pattern[i + 1][j] = -1;
				pattern[i][j + 1] = -1;
				pattern[i + 1][j + 1] = -1;
			}
}
