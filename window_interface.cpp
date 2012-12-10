#include <QtGui>
#include "const.h"
#include "game.h"
#include "output_widget.h"
#include "window_interface.h"

WindowInterface::WindowInterface(QApplication *qapp) {
    app = qapp;
    int imageWidth = W * (CellWidth + LineWidth) + LineWidth;
    int imageHeight = H * (CellHeight + LineWidth) + LineWidth;
    canvas = new QPixmap(imageWidth, imageHeight);
    window = new QMainWindow();
    layout = new QGridLayout();
    scorelabel = new QLabel();
    tableau = new QStatusBar();
    tableau -> addWidget(scorelabel);
    output = new OutputWidget(canvas);
    G = new Game(canvas);
    output -> setLayout(layout);
    window -> setCentralWidget(output);
    window -> setWindowTitle("Figurez");
    output -> setFixedSize(imageHeight, imageHeight);
    window -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    window -> setWindowIcon(QIcon("rabbit-icon.png"));
    window -> layout() -> setSizeConstraint(QLayout::SetFixedSize);
    window -> setStatusBar(tableau);
    menubar = new QMenuBar;
    gamemenu = new QMenu("Game");
    gamemenu -> addAction("New game", G, SLOT(reset()), Qt::CTRL + Qt::Key_N);
    gamemenu -> addAction("Exit", app, SLOT(quit()), Qt::CTRL + Qt::Key_Q);
    QObject::connect(G, SIGNAL(repaint()), output, SLOT(repaint()));
    QObject::connect(output, SIGNAL(fieldPressed(int, int)), G, SLOT(push_field(int, int)));
    QObject::connect(G, SIGNAL(moveFailed()), this, SLOT(showMoveFail()));
    QObject::connect(G, SIGNAL(showScore(int)), this, SLOT(updateScore(int)));
    updateScore(0);
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
