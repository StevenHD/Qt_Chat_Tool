#ifndef TCPDATAPROCESSOR_H
#define TCPDATAPROCESSOR_H

//初始缓冲区大小
#define BUFFER_SIZE 1024

#include <string.h>

class TcpDataProcessor
{
public:
    TcpDataProcessor();
    ~TcpDataProcessor();

    ///缓冲区
    char *m_pBuffer;
    ///缓冲区大小
    int m_nBufferSize;
    ///缓冲区当前数据大小
    int m_nOffset;

    ///获取当前缓冲区数据大小
    int getDataLen();
    ///调整缓冲区大小
    bool reBufferSize(int nLen);
    ///添加消息到缓冲区
    bool addMsg(char *pBuf, int nLen);
    ///缓冲区复位
    void resetBuffer();
    ///移除缓冲区首部的第一个数据包
    void poll(int nLen);
};
#endif  //TCPDATAPROCESSOR_H
