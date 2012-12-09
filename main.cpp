#include <QtGui>
#include <QMainWindow>
#include "const.h"
#include "game.h"
#include <cmath>
#include <ctime>

class OutputWidget : public QFrame {
private:
    QPixmap *canvas;
    Game *G;
protected:
    virtual void paintEvent(QPaintEvent*) {
        QPainter painter(this);
        painter.drawImage(0,0, canvas -> toImage());
    }
    virtual void mousePressEvent(QMouseEvent* event) {
        int x = event -> x();
        int y = event -> y();
        int xpos = (x - LineWidth) / (CellWidth + LineWidth);
        int ypos = (y - LineWidth) / (CellHeight + LineWidth);
        G -> push_field(xpos, ypos);
        this -> repaint();
    }
public:
    OutputWidget(QPixmap* pixmap, Game * Gp) {
        setMouseTracking(true);
        canvas = pixmap;
        G = Gp;
    }
};

class WindowInterface {
private:
    QApplication *app;
    QMainWindow *window;
    QGridLayout *layout;
    QPixmap *canvas;
    QLabel *countlabel;
    QStatusBar *tableau;
    Game *G;
    OutputWidget *output;
    QMenuBar *menubar;
    QMenu *gamemenu;
public:
    WindowInterface(QApplication *qapp) {
        app = qapp;
        int imageWidth = W * (CellWidth + LineWidth) + LineWidth;
        int imageHeight = H * (CellHeight + LineWidth) + LineWidth;
        window = new QMainWindow();
        layout = new QGridLayout();
        canvas = new QPixmap(imageWidth, imageHeight);
        countlabel = new QLabel();
        tableau = new QStatusBar();
        tableau -> addWidget(countlabel);
        G = new Game(canvas, tableau, countlabel);
        output = new OutputWidget(canvas, G);
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
        menubar -> addMenu(gamemenu);
        window -> setMenuBar(menubar);
        window -> show();
    }
};

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    srand(time(0));
    WindowInterface wi(&app);
    return app.exec();
}