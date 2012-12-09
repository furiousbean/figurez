#include <QtGui>
#include <QMainWindow>
#include "rectangle.h"
#include "const.h"
#include "game.h"
#include <cmath>
#include <ctime>

class OutputWidget : public QFrame {
private:
    QPixmap *canvas;
    Game *G;
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QPainter painter(this);
        painter.drawImage(0,0, canvas -> toImage());

    }
    virtual void mousePressEvent(QMouseEvent* event)
    {
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

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  srand(time(0));
  int imageWidth = W * (CellWidth + LineWidth) + LineWidth;
  int imageHeight = H * (CellHeight + LineWidth) + LineWidth;
  QMainWindow *window = new QMainWindow();
  QGridLayout *layout = new QGridLayout();
  QPixmap *canvas = new QPixmap(imageWidth, imageHeight);
  QLabel *countlabel = new QLabel();
  QStatusBar *tableau = new QStatusBar();
  tableau -> addWidget(countlabel);
  Game *G = new Game(canvas, tableau, countlabel);
  OutputWidget *output = new OutputWidget(canvas, G);
  output -> setLayout(layout);
  window -> setCentralWidget(output);
  window -> setWindowTitle("Figurez");
  output -> setFixedSize(imageHeight, imageHeight);
  window -> setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  window -> setWindowIcon(QIcon("rabbit-icon.png"));
  window -> layout() -> setSizeConstraint(QLayout::SetFixedSize);
  window -> setStatusBar(tableau);
  window -> show();

  return app.exec();
}