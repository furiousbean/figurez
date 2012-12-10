#include <QtGui>
#include <cmath>
#include <ctime>
#include "window_interface.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    srand(time(0));
    WindowInterface wi(&app);
    return app.exec();
}
