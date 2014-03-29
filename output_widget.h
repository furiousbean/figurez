#ifndef OUTPUT_WIDGET_H
#define OUTPUT_WIDGET_H
#include <QtWidgets/QFrame>
#include <QPixmap>
#include "const.h"
#include "game.h"

/*!
 * An object which shows current game picture
 */

class OutputWidget : public QFrame {
Q_OBJECT
private:
    QPixmap *canvas;
    const GameParams *Gp;
protected:
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent* event);
public:
    OutputWidget(QPixmap* pixmap, const GameParams &gp);
    OutputWidget(const OutputWidget &ow, QPixmap* pixmap);
signals:
    void fieldPressed(int, int);
};

#endif //OUTPUT_WIDGET_H
