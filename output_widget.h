#ifndef OUTPUT_WIDGET_H
#define OUTPUT_WIDGET_H
#include <QFrame>
#include <QPixmap>
#include "const.h"
#include "game.h"

//object which show current game picture

class OutputWidget : public QFrame {
Q_OBJECT
private:
    QPixmap *canvas;
protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
public:
    OutputWidget(QPixmap* pixmap);
signals:
    void fieldPressed(int, int);
};

#endif //OUTPUT_WIDGET_H
