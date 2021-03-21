#include "breakout.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Breakout b;
    b.show();
    return a.exec();
}
