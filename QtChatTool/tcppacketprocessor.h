#ifndef TCPPACKETPROCESSOR_H
#define TCPPACKETPROCESSOR_H

#include <QString>
#include "TcpDataProcessor.h"

#pragma pack(push,1)

///定义包头
typedef struct
{
    ///包体长度
    int nLen;
}PacketHead;

///定义封包帝对象：包头+包体
typedef struct
{
    PacketHead head;
    char* body;
}Packet;

typedef struct
{
    int number;
    char* data;
}packedData;

#pragma pack(pop)

class TcpPacketProcessor
{
public:
    TcpPacketProcessor();
    ~TcpPacketProcessor();

    TcpDataProcessor m_Buffer;

    ///封包
    packedData packData(char* data, int nLen);
    ///将接收到的数据放在缓冲区后，解包
    QString unpackData(char * data, int nLen);
};

#endif  //TCPPACKETPROCESSOR_H

