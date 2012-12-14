#include <QApplication>
#include <cmath>
#include <ctime>
#include "window_interface.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    srand(time(0));
    GameParams gp;

    WindowInterface wi(&gp);

    //GameParams gp2(10, 15, 24, 24, 1, 5, 2);
    //WindowInterface wi2(&gp2);

    return app.exec();
}
