#include "server.h"
#include <QtWidgets/QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("System");

    /*QTextCodec::setCodecForTr(codec);*/

    QTextCodec::setCodecForLocale(codec);
    /*QTextCodec::setCodecForCStrings(codec);*/
    Server w;
    w.show();

    return a.exec();
}
