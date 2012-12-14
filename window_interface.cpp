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
#include "window_interface.h"

WindowInterface::WindowInterface(QApplication *qapp, GameParams *gp) {
    app = qapp;
    Gp = gp;
    int imageWidth = Gp -> get_W() * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    int imageHeight = Gp -> get_H() * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    canvas = new QPixmap(imageWidth, imageHeight);
    window = new QMainWindow();
    layout = new QGridLayout();
    scorelabel = new QLabel();
    tableau = new QStatusBar();
    tableau -> addWidget(scorelabel);
    output = new OutputWidget(canvas, Gp);
    G = new Game(canvas, Gp);
    output -> setLayout(layout);
    window -> setCentralWidget(output);
    window -> setWindowTitle("Figurez");
    output -> setFixedSize(imageWidth, imageHeight);
    window -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    window -> setWindowIcon(QIcon("rabbit-icon.png"));
    window -> layout() -> setSizeConstraint(QLayout::SetFixedSize);
    window -> setStatusBar(tableau);
    menubar = new QMenuBar;
    gamemenu = new QMenu("Game");
    gamemenu -> addAction("New game", G, SLOT(reset()), Qt::CTRL + Qt::Key_N);
        /**< connect game slots & signals with window interface */
    gamemenu -> addAction("Exit", app, SLOT(quit()), Qt::CTRL + Qt::Key_Q);
    QObject::connect(G, SIGNAL(repaint()), output, SLOT(repaint()));
    QObject::connect(output, SIGNAL(fieldPressed(int, int)), G, SLOT(push_field(int, int)));
    QObject::connect(G, SIGNAL(moveFailed()), this, SLOT(showMoveFail()));
    QObject::connect(G, SIGNAL(showScore(int)), this, SLOT(updateScore(int)));
    updateScore(G -> get_score());
    menubar -> addMenu(gamemenu);
    window -> setMenuBar(menubar);
    window -> show();
}

void WindowInterface::showMoveFail() {
    tableau -> showMessage("Can't move it: there's no way.", 2000);
}

void WindowInterface::updateScore(int score) {
    scorelabel -> setText("Score: " + QString::number(score));
}
