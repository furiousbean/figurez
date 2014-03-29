#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H
#include <QtWidgets/QMainWindow>

#include "const.h"
#include "game.h"
#include "output_widget.h"

/*!
 * A window interface class
 */

class QGridLayout;
class QCloseEvent;
class QPixmap;
class QLabel;
class QStatusBar;
class QMenuBar;
class QMenu;

class WindowInterface : public QMainWindow {
Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event);
private:
    QGridLayout *windowlayout;
    QGridLayout *canvlayout;
    QPixmap *canvas;
    QLabel *scorelabel;
    QStatusBar *tableau;
    Game *G;
    const GameParams *Gp;
    OutputWidget *output;
    QMenuBar *menubar;
    QMenu *gamemenu;
public:
    WindowInterface(const GameParams &gp);
    WindowInterface(const WindowInterface &wi);
    ~WindowInterface();
public slots:
    void showMoveFail();
    void updateScore(int score);

};

#endif //WINDOW_INTERFACE_H
