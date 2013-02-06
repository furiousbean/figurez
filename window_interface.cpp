#include <QMainWindow>
#include <QGridLayout>
#include <QCloseEvent>
#include <QPixmap>
#include <QLabel>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QCoreApplication>
#include "const.h"
#include "game.h"
#include "output_widget.h"
#include "window_interface.h"

WindowInterface::WindowInterface(const GameParams &gp) {
    Gp = &gp;
    int imageWidth = Gp -> get_W() * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    int imageHeight = Gp -> get_H() * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    canvas = new QPixmap(imageWidth, imageHeight);
    canvlayout = new QGridLayout();
    scorelabel = new QLabel();
    tableau = new QStatusBar();
    tableau -> addWidget(scorelabel);
    output = new OutputWidget(canvas, *Gp);
    G = new Game(*canvas, *Gp);
    output -> setLayout(canvlayout);
    this -> setCentralWidget(output);
    this -> setWindowTitle("Figurez");
    output -> setFixedSize(imageWidth, imageHeight);
    this -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this -> setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/rabbit-icon.png"));
    this -> layout() -> setSizeConstraint( QLayout::SetFixedSize );
    this -> setStatusBar(tableau);
    menubar = new QMenuBar;
    gamemenu = new QMenu("Game");
    gamemenu -> addAction("New game", G, SLOT(reset()), Qt::CTRL + Qt::Key_N);
        /**< connect game slots & signals with window interface */
    gamemenu -> addAction("Exit", this, SLOT(close()), Qt::CTRL + Qt::Key_Q);
    QObject::connect(G, SIGNAL(repaint()), output, SLOT(repaint()));
    QObject::connect(output, SIGNAL(fieldPressed(int, int)), G, SLOT(push_field(int, int)));
    QObject::connect(G, SIGNAL(moveFailed()), this, SLOT(showMoveFail()));
    QObject::connect(G, SIGNAL(showScore(int)), this, SLOT(updateScore(int)));
    updateScore(G -> get_score());
    menubar -> addMenu(gamemenu);
    this -> setMenuBar(menubar);
    this -> show();
}

WindowInterface::WindowInterface(const WindowInterface &wi) : QMainWindow() {
    Gp = wi.Gp;
    int imageWidth = Gp -> get_W() * (Gp -> get_CellWidth() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    int imageHeight = Gp -> get_H() * (Gp -> get_CellHeight() + Gp -> get_LineWidth()) + Gp -> get_LineWidth();
    canvas = new QPixmap(*wi.canvas);
    canvlayout = new QGridLayout();
    scorelabel = new QLabel();
    tableau = new QStatusBar();
    tableau -> addWidget(scorelabel);
    output = new OutputWidget(*wi.output, canvas);
    G = new Game(*wi.G, *canvas);
    output -> setLayout(canvlayout);
    this -> setCentralWidget(output);
    this -> setWindowTitle("Figurez");
    output -> setFixedSize(imageWidth, imageHeight);
    this -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this -> setWindowIcon(QIcon("rabbit-icon.png"));
    this -> layout() -> setSizeConstraint( QLayout::SetFixedSize );
    this -> setStatusBar(tableau);
    menubar = new QMenuBar;
    gamemenu = new QMenu("Game");
    gamemenu -> addAction("New game", G, SLOT(reset()), Qt::CTRL + Qt::Key_N);
    gamemenu -> addAction("Exit", this, SLOT(close()), Qt::CTRL + Qt::Key_Q);
    QObject::connect(G, SIGNAL(repaint()), output, SLOT(repaint()));
    QObject::connect(output, SIGNAL(fieldPressed(int, int)), G, SLOT(push_field(int, int)));
    QObject::connect(G, SIGNAL(moveFailed()), this, SLOT(showMoveFail()));
    QObject::connect(G, SIGNAL(showScore(int)), this, SLOT(updateScore(int)));
    updateScore(G -> get_score());
    menubar -> addMenu(gamemenu);
    this -> setMenuBar(menubar);
    this -> show(); 
}

void WindowInterface::showMoveFail() {
    tableau -> showMessage("Can't move it: there's no way.", 2000);
}

WindowInterface::~WindowInterface() {

}

void WindowInterface::closeEvent(QCloseEvent *event) {
    event -> accept();
    delete G;
    delete canvas;
}

void WindowInterface::updateScore(int score) {
    scorelabel -> setText("Score: " + QString::number(score));
}

