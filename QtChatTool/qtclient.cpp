#include "qtclient.h"
#include <QDebug>

QtClient::QtClient(QWidget *parent, Qt::WindowFlags flags)
    : QWidget(parent, flags)
{
    ui.setupUi(this);
    this->initTCP();

    /////文件传送相关变量初始化
    ///每次发送数据大小为64kb
    perDataSize = 64 * 1024;
    totalBytes = 0;
    bytestoWrite = 0;
    bytesWritten = 0;
    bytesReceived = 0;
    filenameSize = 0;

    connect(ui.lineEdit_currentPath, SIGNAL(textChanged(QString)), this, SLOT(lineEditTextChanged(QString)));
    connect(this->ui.pushButton_openFile, SIGNAL(clicked()), this, SLOT(selectFile()));
    connect(this->ui.pushButton_sendFile, SIGNAL(clicked()), this, SLOT(sendFile()));
    connect(this->ui.pushButton_sendPicture, SIGNAL(clicked()), this, SLOT(sendPicture()));

    //The following code is to show picture
    QTextCodec *codec = QTextCodec::codecForName("System");

    /*QTextCodec::setCodecForTr(codec);*/

    QTextCodec::setCodecForLocale(codec);
    /*QTextCodec::setCodecForCStrings(codec);*/

    currentDirPath = "";
    numofPic = 0;

    ///The function of FileBrower slot
    connect(ui.lineEdit_currentPath, SIGNAL(returnPressed()), this, SLOT(showCurrentDirFiles));
    connect(ui.listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(showNextDirFiles(QListWidgetItem*)));

    ///The function of showing picture slot
    connect(ui.listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(playCurrentItem(QListWidgetItem*)));
}

QtClient::~QtClient()
{
}

void QtClient::initTCP()
{
    this->tcpSocket = new QTcpSocket(this);
    connect(ui.pushButton_connect, SIGNAL(clicked()), this, SLOT(connectServer()));
    connect(ui.pushButton_disconnect, SIGNAL(clicked()), this, SLOT(disconnectServer()));
    connect(ui.pushButton_send, SIGNAL(clicked()), this, SLOT(sendData()));
}

void QtClient::connectServer()
{
    tcpSocket->abort();
    tcpSocket->connectToHost("127.0.0.1", 6666);
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
}

void QtClient::disconnectServer()
{
    ;
}

void QtClient::receiveData()
{
    /////获取当前时间
    current_date_time = QDateTime::currentDateTime();
    str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss") + "\n";

    ////接收数据
    QString str = tcpSocket->readAll();
    ////显示
    str = "Server " + str_date_time + str;
    this->ui.textEdit->append(str);
}

void QtClient::sendData()
{
    ////发送数据
    QString str = ui.lineEdit->text();
    this->tcpSocket->write(ui.lineEdit->text().toLatin1());
    ////显示
    current_date_time = QDateTime::currentDateTime();
    str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    str = "You " + str_date_time + "\n" + str;
    ui.textEdit->append(str);
}

void QtClient::selectFile()
{
    this->fileSocket = new QTcpSocket(this);
    fileSocket->abort();
    fileSocket->connectToHost("127.0.0.1", 8888);
    ////文件传送进度更新
    connect(fileSocket, SIGNAL(bytesWritten(qint64)), this, SLOT(updateFileProgress(qint64)));
    connect(fileSocket, SIGNAL(readyRead()), this, SLOT(updateFileProgress()));

    this->ui.progressBar->setValue(0);
    this->filename = QFileDialog::getOpenFileName(this, "Open a file", "/", "files (*)");
    ui.lineEdit_flieName->setText(filename);
    showPicture();
}

void QtClient::sendFile()
{
    this->localFile = new QFile(filename);
    if (!localFile->open(QFile::ReadOnly))
    {
        ui.textEdit->append(tr("Client:open file error!"));
        return;
    }
    ///获取文件大小
    this->totalBytes = localFile->size();
    QDataStream sendout(&outBlock, QIODevice::WriteOnly);
    sendout.setVersion(QDataStream::Qt_5_12);
    QString currentFileName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

    qDebug() << sizeof(currentFileName);
    ////保留总代大小信息空间、文件名大小信息空间、文件名
    sendout << qint64(0) << qint64(0) << currentFileName;
    totalBytes += outBlock.size();
    sendout.device()->seek(0);
    sendout << totalBytes << qint64((outBlock.size() - sizeof(qint64) * 2));

    bytestoWrite = totalBytes - fileSocket->write(outBlock);
    outBlock.resize(0);
}

void QtClient::updateFileProgress(qint64 numBytes)
{
    ////已经发送的数据大小
    bytesWritten += (int)numBytes;

    ////如果已经发送了数据
    if (bytestoWrite > 0)
    {
        outBlock = localFile->read(qMin(bytestoWrite, perDataSize));
        ///发送完一次数据后还剩余数据的大小
        bytestoWrite -= ((int)fileSocket->write(outBlock));
        ///清空发送缓冲区
        outBlock.resize(0);
    }
    else
        localFile->close();

    ////更新进度条
    this->ui.progressBar->setMaximum(totalBytes);
    this->ui.progressBar->setValue(bytesWritten);

    ////如果发送完毕
    if (bytesWritten == totalBytes)
    {
        localFile->close();
        //fileSocket->close();
    }
}

void QtClient::updateFileProgress()
{
    QDataStream inFile(this->fileSocket);
    inFile.setVersion(QDataStream::Qt_5_12);

    ///如果接收到的数据小于16个字节，保存到来的文件头结构
    if (bytesReceived <= sizeof(qint64) * 2)
    {
        if ((fileSocket->bytesAvailable() >= (sizeof(qint64)) * 2) && (filenameSize == 0))
        {
            inFile >> totalBytes >> filenameSize;
            bytesReceived += sizeof(qint64) * 2;
        }
        if ((fileSocket->bytesAvailable() >= filenameSize) && (filenameSize != 0))
        {
            inFile >> filename;
            bytesReceived += filenameSize;
            filename = "ServerData/" + filename;
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
        bytesReceived += fileSocket->bytesAvailable();
        inBlock = fileSocket->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }

    ////数据接收完成时
    if (bytesReceived == totalBytes)
    {
        this->ui.textEdit->append("Receive file successfully!");
        //QImage image(QString("%1.png").arg(pics));//QImage's Constructor takes a file path
        /*this->ui.label->setPixmap(QPixmap::fromImage(image));*/
        bytesReceived = 0;
        totalBytes = 0;
        filenameSize = 0;
        localFile->close();
        //fileSocket->close();
    }
}

//The following code is to show picture
///
void QtClient::playCurrentItem(QListWidgetItem* item)
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

void QtClient::lineEditTextChanged(QString str)
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
        ui.lineEdit_currentPath->setText(dir.absolutePath());
        showCurrentDirFiles();
    }
    ///获取鼠标双击的文件名字
    /*QString strName = item->text();*/

    //QDir dir;
    ////设置路径为当前目录路径
    ///*qDebug() << "path: " << ui.lineEdit->text() << endl;*/
    //QString strPath = ui.lineEdit->text();
    //dir.setPath(ui.lineEdit->text());

    ////重新设置路径
    //dir.cd(str);
    ////更新当前显示路径,并显示当前目录下所有文件
    //ui.lineEdit_currentPath->setText(dir.absolutePath());
    //showCurrentDirFiles();
    //ui.listWidget->addItem(str);
}

///showing picture
void QtClient::showPicture()
{
    //QListWidgetItem* item = ui.listWidget->item(num);
    QString itemPic = ui.lineEdit_flieName->text();
    //QString strName = item->text();

    ///获取当前图片的绝对路径
   // QPixmap pic(currentDirPath + "/" + strName);
    QPixmap pics(itemPic);
    ui.label->setScaledContents(true);

    ui.label->setPixmap(pics);
    //ui.label->setPixmap(pic);
}

void QtClient::showFileInfoList(QFileInfoList pInfoList)
{
    numofPic = 0;
    ui.listWidget->clear();

    for (int i = 0; i<pInfoList.size(); i++)
    {
        QFileInfo tmpInfo = pInfoList.at(i);
        QString pFileName = tmpInfo.fileName();
        QListWidgetItem *tmpItem = new QListWidgetItem(pFileName);
        if (tmpInfo.isDir()) tmpItem->setIcon(*getItemPropertyIcon(1));
        else
        {
            tmpItem->setIcon(*getItemPropertyIcon(2));
            ///获取文件后缀名
            QString suffix = tmpInfo.suffix();
            ///只选取*.jpg,*.png格式文件
            if (suffix.indexOf("jpg")<0 && suffix.indexOf("png")<0)
                continue;
            else
                numofPic++;
        }
        ui.listWidget->addItem(tmpItem);
    }

}

void QtClient::showCurrentDirFiles()
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

void QtClient::showNextDirFiles(QListWidgetItem *item)
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

QIcon * QtClient::getItemPropertyIcon(int iType)
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

void QtClient::sendPicture(QListWidgetItem *item)
{

    ///获取鼠标双击的文件名字
    QString picName = item->text() + "/";
    //更新当前显示路径,并显示当前目录下所有文件
    QString tempPic = ui.lineEdit_currentPath->text() + picName;

    /*this->localFile = new QFile(filename);*/
    this->desiredSendPicture = new QFile(tempPic);

    //if (!localFile->open(QFile::ReadOnly))
    //{
    //	ui.textEdit->append(tr("Client:open file error!"));
    //	return;
    //}

    if (!desiredSendPicture->open(QFile::ReadOnly))
    {
        ui.textEdit->append(tr("Client:open image error!"));
        return;
    }
    /////获取文件大小
    //this->totalBytes = localFile->size();
    //QDataStream sendout(&outBlock, QIODevice::WriteOnly);
    //sendout.setVersion(QDataStream::Qt_5_8);
    //QString currentFileName = filename.right(filename.size() - filename.lastIndexOf('/') - 1);

    ///获取图片大小
    this->totalBytesofPicture = desiredSendPicture->size();
    QDataStream sendoutPic(&outBlockPic, QIODevice::WriteOnly);
    sendoutPic.setVersion(QDataStream::Qt_5_12);
    QString currentPictureName = tempPic.right(tempPic.size() - tempPic.lastIndexOf('/') - 1);

    //qDebug() << sizeof(currentFileName);
    qDebug() << sizeof(currentPictureName);

    ////保留总代大小信息空间、文件名大小信息空间、文件名
    //sendout << qint64(0) << qint64(0) << currentFileName;
    //totalBytes += outBlock.size();
    //sendout.device()->seek(0);
    //sendout << totalBytes << qint64((outBlock.size() - sizeof(qint64) * 2));

    sendoutPic << qint64(0) << qint64(0) << currentPictureName;
    totalBytesofPicture += outBlockPic.size();
    sendoutPic.device()->seek(0);
    sendoutPic << totalBytesofPicture << qint64((outBlockPic.size() - sizeof(qint64) * 2));

    /*bytestoWrite = totalBytes - fileSocket->write(outBlock);
    outBlock.resize(0);*/

    bytestoWritePic = totalBytesofPicture - pictureSocket->write(outBlockPic);
    outBlockPic.resize(0);
}
