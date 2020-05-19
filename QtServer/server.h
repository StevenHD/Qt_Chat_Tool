#ifndef QTSERVER_H
#define QTSERVER_H

#include <QtWidgets/QApplication>
#include <QDebug>
#include "ui_Server.h"

#include <QtNetwork>
#include <QAbstractSocket>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDateTime>
#include <QDataStream>

#include <QFile>
#include <QFileDialog>

///字符编码
#include <QTextcodec>

///图标
#include <QIcon>

///目录
#include <QDir>

///图片
#include <QPixmap>

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~Server();

    QTcpServer *server;
    QTcpSocket *socket;
    QTcpServer *fileserver;
    QTcpSocket *filesocket;

    //The following funcs is to show pictures
    /// Show the details of current Dir in QListWidget
    void showFileInfoList(QFileInfoList pInfoList);

    ///根据文件性质获取图标
    ///iType=1:文件夹
    ///iType=2:文件
    QIcon *getItemPropertyIcon(int iType);

    ///Showing the current picture
    void showPicture(int num);

    public slots:
    ///显示当前目录下的文件夹和文件
    void showCurrentDirFiles();

    ///显示鼠标双击下的的文件夹的文件
    void showNextDirFiles(QListWidgetItem *item);

    ///鼠标点击列表时显示
    void playCurrentItem(QListWidgetItem *item);

    void lineEditTextChanged(QString);


private slots:
    void sendMessage();
    void acceptConnection();
    ////接收客户端发送的数据
    void receiveData();

    void acceptFileConnection();
    void updateFileProgress();
    void displayError(QAbstractSocket::SocketError socketError);

    ///选择发送的文件
    void selectFile();
    void sendFile();
    ////更新文件传送进度
    void updateFileProgress(qint64);

private:
    Ui::Server ui;

    ////传送文件相关变量
    qint64 totalBytes;
    qint64 bytesReceived;
    qint64 bytestoWrite;
    qint64 bytesWritten;
    qint64 filenameSize;
    QString filename;
    ///每次发送数据大小
    qint64 perDataSize;
    QFile *localFile;
    ////本地缓冲区
    QByteArray inBlock;
    QByteArray outBlock;

    ////系统时间
    QDateTime current_date_time;
    QString str_date_time;

    //The following variable is to showing picture
    ///当前文件夹的路径
    QString currentDirPath;
    QString currentDirPicPath;

    ///当前文件夹里的图片数量
    int numofPic;
};

#endif // QTSERVER_H
