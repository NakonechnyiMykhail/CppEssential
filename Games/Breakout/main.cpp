#include "breakout.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Breakout window;

    window.resize(300, 400);
    window.setWindowTitle("Breakout");
    window.show();

    return app.exec();
}
