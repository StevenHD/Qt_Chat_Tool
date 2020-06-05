#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QtWidgets/QApplication>
#include <QDebug>
#include "ui_qtclient.h"
#include <QtNetwork>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDataStream>
#include <QByteArray>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>

//The following command line is to show picture
#include <QTextCodec>
#include <QIcon>
#include <QDir>
#include <QTimer>
#include <QPixmap>

#include <QListWidget>

class QtClient : public QWidget
{
    Q_OBJECT

public:
    QtClient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~QtClient();

    void initTCP();
    /*void newConnect();*/

private slots:
    ////连接服务器
    void connectServer();
    ////与服务器断开连接
    void disconnectServer();
    ////接收服务器发送的数据
    void receiveData();
    ////向服务器发送数据
    void sendData();

    ////浏览文件
    void selectFile();
    ////发送文件
    void sendFile();
    ////Transferring the Picture
    void sendPicture(QListWidgetItem *item);
    ////更新文件发送进度
    void updateFileProgress(qint64);
    ////更新文件接收进度
    void updateFileProgress();

    //The following code is to show picture

    /*show the contents of current Dir in showFileInfoList*/
    void showFileInfoList(QFileInfoList pInfoList);

    /*Based on the property of file to obtain icon*/
    ///iType=1:文件夹
    ///iType=2:文件
    QIcon *getItemPropertyIcon(int iType);

    /// Show current picture
    void showPicture();

public slots:
    ///show folders and items of current Dir
    void showCurrentDirFiles();

    ///show items of folders when clicking doubly lists
    void showNextDirFiles(QListWidgetItem * item);


    ///show list when click
    void playCurrentItem(QListWidgetItem *item);

    void lineEditTextChanged(QString);


private:
    Ui::QtClient ui;
    QTcpSocket *tcpSocket;
    QTcpSocket *fileSocket;
    QTcpSocket *pictureSocket;

    ///文件传送
    QFile *localFile;

    ///图片传送 將QPixmap改爲QFile
    QFile *desiredSendPicture;
    ///文件大小
    qint64 totalBytes;      //文件总字节数
    qint64 totalBytesofPicture; //圖片縂字節數
    qint64 bytesWritten;    //已发送的字节数
    qint64 bytestoWrite;    //尚未发送的字节数
    qint64 bytestoWritePic;
    qint64 filenameSize;    //文件名字的字节数
    qint64 bytesReceived;   //接收的字节数
                            ///每次发送数据大小
    qint64 perDataSize;
    QString filename;

    QString pictureName;
    ///数据缓冲区
    QByteArray inBlock;
    QByteArray outBlock;
    QByteArray outBlockPic;
    QByteArray inBlockPic;

    ////系统时间
    QDateTime current_date_time;
    QString str_date_time;

    //The following code is to show picture

    ///current path of folder
    QString currentDirPath;

    ///The number of pictures in current folders
    int numofPic;
};

#endif // QTCLIENT_H
