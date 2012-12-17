#include <QApplication>
#include <cmath>
#include <ctime>
#include "window_interface.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    srand(time(0));
    GameParams gp;

    WindowInterface wi(gp);
    //WindowInterface wi2(wi);

    return app.exec();
}
