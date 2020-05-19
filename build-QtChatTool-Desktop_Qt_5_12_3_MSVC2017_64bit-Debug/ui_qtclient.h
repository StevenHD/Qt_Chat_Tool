/********************************************************************************
** Form generated from reading UI file 'qtclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCLIENT_H
#define UI_QTCLIENT_H

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

class Ui_QtClient
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_currentPath;
    QLineEdit *lineEdit_flieName;
    QListWidget *listWidget;
    QProgressBar *progressBar;
    QPushButton *pushButton_connect;
    QPushButton *pushButton_disconnect;
    QPushButton *pushButton_openFile;
    QPushButton *pushButton_send;
    QPushButton *pushButton_sendFile;
    QPushButton *pushButton_sendPicture;
    QTextEdit *textEdit;
    QWidget *widget;
    QLabel *label;

    void setupUi(QWidget *QtClient)
    {
        if (QtClient->objectName().isEmpty())
            QtClient->setObjectName(QString::fromUtf8("QtClient"));
        QtClient->resize(733, 712);
        lineEdit = new QLineEdit(QtClient);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 390, 171, 31));
        lineEdit_currentPath = new QLineEdit(QtClient);
        lineEdit_currentPath->setObjectName(QString::fromUtf8("lineEdit_currentPath"));
        lineEdit_currentPath->setGeometry(QRect(240, 60, 201, 41));
        lineEdit_flieName = new QLineEdit(QtClient);
        lineEdit_flieName->setObjectName(QString::fromUtf8("lineEdit_flieName"));
        lineEdit_flieName->setGeometry(QRect(30, 520, 161, 31));
        listWidget = new QListWidget(QtClient);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(240, 150, 201, 192));
        progressBar = new QProgressBar(QtClient);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(490, 70, 181, 31));
        progressBar->setValue(24);
        pushButton_connect = new QPushButton(QtClient);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        pushButton_connect->setGeometry(QRect(460, 180, 121, 31));
        pushButton_disconnect = new QPushButton(QtClient);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(600, 180, 111, 31));
        pushButton_openFile = new QPushButton(QtClient);
        pushButton_openFile->setObjectName(QString::fromUtf8("pushButton_openFile"));
        pushButton_openFile->setGeometry(QRect(30, 600, 93, 28));
        pushButton_send = new QPushButton(QtClient);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));
        pushButton_send->setGeometry(QRect(120, 460, 93, 28));
        pushButton_sendFile = new QPushButton(QtClient);
        pushButton_sendFile->setObjectName(QString::fromUtf8("pushButton_sendFile"));
        pushButton_sendFile->setGeometry(QRect(150, 600, 93, 28));
        pushButton_sendPicture = new QPushButton(QtClient);
        pushButton_sendPicture->setObjectName(QString::fromUtf8("pushButton_sendPicture"));
        pushButton_sendPicture->setGeometry(QRect(520, 550, 121, 41));
        textEdit = new QTextEdit(QtClient);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 40, 181, 311));
        widget = new QWidget(QtClient);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(460, 270, 241, 241));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 231, 231));

        retranslateUi(QtClient);

        QMetaObject::connectSlotsByName(QtClient);
    } // setupUi

    void retranslateUi(QWidget *QtClient)
    {
        QtClient->setWindowTitle(QApplication::translate("QtClient", "QtClient", nullptr));
        pushButton_connect->setText(QApplication::translate("QtClient", "Connect", nullptr));
        pushButton_disconnect->setText(QApplication::translate("QtClient", "Disconnect", nullptr));
        pushButton_openFile->setText(QApplication::translate("QtClient", "Open File", nullptr));
        pushButton_send->setText(QApplication::translate("QtClient", "Send", nullptr));
        pushButton_sendFile->setText(QApplication::translate("QtClient", "Send File", nullptr));
        pushButton_sendPicture->setText(QApplication::translate("QtClient", "Send Picture", nullptr));
        label->setText(QApplication::translate("QtClient", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtClient: public Ui_QtClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCLIENT_H
