<<<<<<< HEAD
#include "QtClient.h"
#include <QtWidgets/QApplication>
=======
#include "server.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>
>>>>>>> 提交说明

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
<<<<<<< HEAD
    QtClient w;

    w.show();

=======
    QTextCodec *codec = QTextCodec::codecForName("System");

    /*QTextCodec::setCodecForTr(codec);*/

    QTextCodec::setCodecForLocale(codec);
    /*QTextCodec::setCodecForCStrings(codec);*/
    Server w;
    w.show();
>>>>>>> 提交说明
    return a.exec();
}
