#include "QtClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtClient w;

    w.show();

    return a.exec();
}
