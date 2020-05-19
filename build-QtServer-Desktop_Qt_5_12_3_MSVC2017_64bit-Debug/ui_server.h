/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QTextEdit *browser;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_currentPath;
    QLineEdit *lineEdit_fileName;
    QListWidget *listWidget;
    QProgressBar *progressBar_fileProgress;
    QPushButton *pushButton;
    QPushButton *pushButton_selectFile;
    QPushButton *pushButton_send;
    QPushButton *pushButton_sendFile;
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QString::fromUtf8("Server"));
        Server->resize(760, 724);
        browser = new QTextEdit(Server);
        browser->setObjectName(QString::fromUtf8("browser"));
        browser->setGeometry(QRect(40, 40, 171, 301));
        lineEdit = new QLineEdit(Server);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(40, 370, 161, 51));
        lineEdit_currentPath = new QLineEdit(Server);
        lineEdit_currentPath->setObjectName(QString::fromUtf8("lineEdit_currentPath"));
        lineEdit_currentPath->setGeometry(QRect(260, 60, 211, 41));
        lineEdit_fileName = new QLineEdit(Server);
        lineEdit_fileName->setObjectName(QString::fromUtf8("lineEdit_fileName"));
        lineEdit_fileName->setGeometry(QRect(40, 520, 151, 41));
        listWidget = new QListWidget(Server);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(230, 150, 221, 251));
        progressBar_fileProgress = new QProgressBar(Server);
        progressBar_fileProgress->setObjectName(QString::fromUtf8("progressBar_fileProgress"));
        progressBar_fileProgress->setGeometry(QRect(490, 60, 201, 31));
        progressBar_fileProgress->setValue(24);
        pushButton = new QPushButton(Server);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(570, 610, 91, 31));
        pushButton_selectFile = new QPushButton(Server);
        pushButton_selectFile->setObjectName(QString::fromUtf8("pushButton_selectFile"));
        pushButton_selectFile->setGeometry(QRect(30, 610, 121, 41));
        pushButton_send = new QPushButton(Server);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(140, 450, 81, 31));
        pushButton_sendFile = new QPushButton(Server);
        pushButton_sendFile->setObjectName(QString::fromUtf8("pushButton_sendFile"));
        pushButton_sendFile->setGeometry(QRect(180, 610, 121, 41));
        widget = new QWidget(Server);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(470, 160, 271, 331));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 231, 281));

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QWidget *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", nullptr));
        pushButton->setText(QApplication::translate("Server", "Close", nullptr));
        pushButton_selectFile->setText(QApplication::translate("Server", "Select File", nullptr));
        pushButton_send->setText(QApplication::translate("Server", "Send", nullptr));
        pushButton_sendFile->setText(QApplication::translate("Server", "Send File", nullptr));
        label->setText(QApplication::translate("Server", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
