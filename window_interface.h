#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H
#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QPixmap>
#include <QLabel>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>

#include "const.h"
#include "game.h"
#include "output_widget.h"

class WindowInterface : public QObject {
Q_OBJECT
private:
    QApplication *app;
    QMainWindow *window;
    QGridLayout *layout;
    QPixmap *canvas;
    QLabel *scorelabel;
    QStatusBar *tableau;
    Game *G;
    OutputWidget *output;
    QMenuBar *menubar;
    QMenu *gamemenu;
public:
    WindowInterface(QApplication *qapp);
public slots:
    void showMoveFail();
    void updateScore(int score);
};

#endif //WINDOW_INTERFACE_H