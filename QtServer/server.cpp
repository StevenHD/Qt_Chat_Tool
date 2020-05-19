#include "Server.h"
#include <QDataStream>
#include <QMessageBox>
#include <QString>
#include <QByteArray>

Server::Server(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);

    this->socket = new QTcpSocket(this);
    this->server = new QTcpServer(this);
    this->server->listen(QHostAddress::Any, 6666);
    connect(this->server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(sendMessage()));

    ///文件传送套接字
    this->filesocket = new QTcpSocket(this);
    this->fileserver = new QTcpServer(this);
    this->fileserver->listen(QHostAddress::Any, 8888);
    connect(this->fileserver, SIGNAL(newConnection()), this, SLOT(acceptFileConnection()));

    //// 文件传送相关变量初始化
    bytesReceived = 0;
    totalBytes = 0;
    filenameSize = 0;

    connect(ui.lineEdit_currentPath, SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    connect(ui.pushButton_selectFile, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(ui.pushButton_sendFile, SIGNAL(clicked()), this, SLOT(sendFile()));


    //The following code is to show picture
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForLocale(codec);

    currentDirPath = "";
    numofPic = 0;

    ///FileBrowser slot Function
    connect(ui.lineEdit_currentPath, SIGNAL(returnPressed()), this, SLOT(showCurrentDirFiles()));
    connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showNextDirFiles(QListWidgetItem*)));


    //ShowPicture slot Function
    connect(ui.listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(playCurrentItem(QListWidgetItem*)));

}

Server::~Server()
{

}

void Server::acceptConnection()
{
    this->socket = this->server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

void Server::acceptFileConnection()
{
    bytesWritten = 0;
    ///每次发送数据大小为64kb
    perDataSize = 64 * 1024;
    this->filesocket = this->fileserver->nextPendingConnection();
    ///接受文件
    connect(filesocket, SIGNAL(readyRead()), this, SLOT(updateFileProgress()));
    connect(filesocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(updateFileProgress(qint64)));
    connect(filesocket, SIGNAL(bytesWritten(qint64)), this, SLOT(displayError(QAbstractSocket::SocketError socketError)));
}

void Server::sendMessage()
{
    this->socket->write(ui.lineEdit->text().toLatin1());
    ////显示
    current_date_time = QDateTime::currentDateTime();
    str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QString str = "You " + str_date_time + "\n" + ui.lineEdit->text();
    ui.browser->append(str);
}

void Server::receiveData()
{
    /////获取当前时间
    current_date_time = QDateTime::currentDateTime();
    str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss") + "\n";

    ////接收数据
    QString str = this->socket->readAll();
    QPixmap picture;
    picture.loadFromData(inBlock, "png");
    ////显示
    str = "Client " + str_date_time + str;
    this->ui.browser->append(str);
    this->ui.label->setPixmap(picture);
}

void Server::updateFileProgress()
{
    QDataStream inFile(this->filesocket);
    inFile.setVersion(QDataStream::Qt_5_8);

    ///如果接收到的数据小于16个字节，保存到来的文件头结构
    if (bytesReceived <= sizeof(qint64) * 2)
    {
        if ((filesocket->bytesAvailable() >= (sizeof(qint64)) * 2) && (filenameSize == 0))
        {
            inFile >> totalBytes >> filenameSize;
            bytesReceived += sizeof(qint64) * 2;
        }
        if ((filesocket->bytesAvailable() >= filenameSize) && (filenameSize != 0))
        {
            inFile >> filename;
            bytesReceived += filenameSize;
            filename = "ClientData/" + filename;
            localFile = new QFile(filename);
            if (!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "Server::open file error!";
                return;
            }
        }
        else
            return;
    }
    /////如果接收的数据小于总数据，则写入文件
    if (bytesReceived < totalBytes)
    {
        bytesReceived += filesocket->bytesAvailable();
        inBlock = filesocket->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ////更新进度条显示
    this->ui.progressBar_fileProgress->setMaximum(totalBytes);
    this->ui.progressBar_fileProgress->setValue(bytesReceived);
    ////数据接收完成时
    if (bytesReceived == totalBytes)
    {
        this->ui.browser->append("Receive file successfully!");

        QString strFileName = filename;
        if (strFileName.indexOf("jpg") >= 0 || strFileName.indexOf("png") >= 0)
        {

            QString currentDirPicPath = "";
            QPixmap pic(currentDirPicPath + "C:/VS/QtTcp/QtTcp/Server/Server/" + strFileName);
            this->ui.label->setScaledContents(true);
            this->ui.label->setPixmap(pic);
        }


        bytesReceived = 0;
        totalBytes = 0;
        filenameSize = 0;
        localFile->close();
        //filesocket->close();
    }
}

void Server::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << socket->errorString();
    socket->close();
}

void Server::selectFile()
{
    filesocket->open(QIODevice::WriteOnly);
    ////文件传送进度更新
    connect(filesocket, SIGNAL(bytesWritten(qint64)), this, SLOT(updateFileProgress(qint64)));

    this->filename = QFileDialog::getOpenFileName(this, "Open a file", "/", "files (*)");
    ui.lineEdit_fileName->setText(filename);
}

void Server::sendFile()
{
    this->localFile = new QFile(filename);
    if (!localFile->open(QFile::ReadOnly))
    {
        return;
    }
    ///获取文件大小
    this->totalBytes = localFile->size();
    QDataStream sendout(&outBlock, QIODevice::WriteOnly);
    sendout.setVersion(QDataStream::Qt_5_8);
    QString currentFileName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

    ////保留总代大小信息空间、文件名大小信息空间、文件名
    sendout << qint64(0) << qint64(0) << currentFileName;
    totalBytes += outBlock.size();
    sendout.device()->seek(0);
    sendout << totalBytes << qint64((outBlock.size() - sizeof(qint64) * 2));

    bytestoWrite = totalBytes - filesocket->write(outBlock);
    outBlock.resize(0);
}

void Server::updateFileProgress(qint64 numBytes)
{
    ////已经发送的数据大小
    bytesWritten += (int)numBytes;

    ////如果已经发送了数据
    if (bytestoWrite > 0)
    {
        outBlock = localFile->read(qMin(bytestoWrite, perDataSize));
        ///发送完一次数据后还剩余数据的大小
        bytestoWrite -= ((int)filesocket->write(outBlock));
        ///清空发送缓冲区
        outBlock.resize(0);
    }
    else
        localFile->close();

    ////如果发送完毕
    if (bytesWritten == totalBytes)
    {
        localFile->close();
        //filesocket->close();
    }
}

//The following definition of functions is to show pictures

void Server::playCurrentItem(QListWidgetItem* item)
{
    QString strName = item->text();
    if (strName.indexOf("jpg") >= 0 || strName.indexOf("png") >= 0)
    {
        ///获取当前图片的绝对路径
        QPixmap pic(currentDirPath + "/" + strName);
        ui.label->setScaledContents(true);
        ui.label->setPixmap(pic);
    }
}

//显示图片
void Server::showPicture(int num)
{
    QListWidgetItem* item = ui.listWidget->item(num);
    QString strName = item->text();

    ///获取当前图片的绝对路径
    QPixmap pic(currentDirPath + "/" + strName);
    ui.label->setScaledContents(true);
    ui.label->setPixmap(pic);
}


void Server::showFileInfoList(QFileInfoList pInfoList)
{
    numofPic = 0;
    ui.listWidget->clear();

    for (int i = 0; i < pInfoList.size(); i++)
    {
        QFileInfo tmpInfo = pInfoList.at(i);
        QString pFileName = tmpInfo.fileName();
        QListWidgetItem *tmpItem = new QListWidgetItem(pFileName);

        if (tmpInfo.isDir())
            tmpItem->setIcon(*getItemPropertyIcon(1));
        else
        {
            tmpItem->setIcon(*getItemPropertyIcon(2));
            ///Obtain the suffix of file
            QString suffix = tmpInfo.suffix();

            ///Just select files which are .jpg and .png
            if (suffix.indexOf("jpg") < 0 && suffix.indexOf("png") < 0)
                continue;
            else
                numofPic++;
        }
    ui.listWidget->addItem(tmpItem);
    }
}

//void Server::showNextDirFiles(QListWidgetItem *item)
//{
//	///获取鼠标双击的文件名字
//	QString strName = item->text();
//	QDir dir;
//	//设置路径为当前目录路径
//	dir.setPath(ui.lineEdit->text());
//	//重新设置路径
//	dir.cd(strName);
//	//更新当前显示路径,并显示当前目录下所有文件
//	ui.lineEdit->setText(dir.absolutePath());
//	showCurrentDirFiles();
//}

void Server::showNextDirFiles(QListWidgetItem *item)
{
    ///获取鼠标双击的文件名字
    QString strName = item->text() + "/";
    //更新当前显示路径,并显示当前目录下所有文件
    QString temp = ui.lineEdit_currentPath->text() + strName;
    if (temp.contains(".png") || temp.contains(".jpg"))
    {
        /*temp.remove("/");*/
        // 移除末尾
        temp.chop(1);
    }
    ui.lineEdit_currentPath->setText(temp);
    showCurrentDirFiles();
}

void Server::lineEditTextChanged(QString str)
{
    if (QString("C:/") == str)
    {
        QDir dir;
        //设置路径为当前目录路径
        /*qDebug() << "path: " << ui.lineEdit->text() << endl;*/
        QString strPath = ui.lineEdit->text();
        dir.setPath(ui.lineEdit->text());

        //重新设置路径
        dir.cd(str);
        //更新当前显示路径,并显示当前目录下所有文件
//		ui.lineEdit_currentPath->setText(dir.absolutePath());
        showCurrentDirFiles();
    }
    ///获取鼠标双击的文件名字
    /*QString strName = item->text();*/

    //QDir dir;
    ////设置路径为当前目录路径
    //qDebug() << "path: " << ui.lineEdit->text() << endl;*/
    //QString strPath = ui.lineEdit->text();
    //dir.setPath(ui.lineEdit->text());

    ////重新设置路径
    //dir.cd(str);
    ////更新当前显示路径,并显示当前目录下所有文件
    //ui.lineEdit_currentPath->setText(dir.absolutePath());
    //showCurrentDirFiles();
    //ui.listWidget->addItem(str);
}

void Server::showCurrentDirFiles()
{
    //获取当前输入的目录
    QDir currentDir(ui.lineEdit_currentPath->text());
    QStringList fileList;
    fileList << "*";
    QFileInfoList infoList = currentDir.entryInfoList(fileList, QDir::AllEntries, QDir::DirsFirst);
    //在QListWidget里显示文件列表
    this->showFileInfoList(infoList);

    //记录当前路径
    if (!infoList.isEmpty())
    {
        this->currentDirPath = infoList[0].absoluteFilePath();
        qDebug() << currentDirPath;
    }
}

QIcon * Server::getItemPropertyIcon(int iType)
{
    QDir dir;
    QString path = dir.currentPath();
    switch (iType)
    {
    case 1:
        return new QIcon(path + "/Folder.png");
        break;
    case 2:
        return new QIcon(path + "/File.png");
        break;
    }
    return NULL;
}
