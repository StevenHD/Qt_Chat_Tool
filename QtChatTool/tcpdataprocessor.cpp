#include "TcpDataProcessor.h"

TcpDataProcessor::TcpDataProcessor()
{
    m_nBufferSize = BUFFER_SIZE;
    m_nOffset = 0;
    m_pBuffer = new char[m_nBufferSize];
    memset(m_pBuffer, 0, sizeof(m_pBuffer));
}

TcpDataProcessor::~TcpDataProcessor()
{

}

int TcpDataProcessor::getDataLen()
{
    return this->m_nOffset;
}

bool TcpDataProcessor::reBufferSize(int nLen)
{
    //保存原缓冲区地址
    char *oBuffer = m_pBuffer;
    //try
    {
        //保证最小大小
        nLen = nLen < 64 ? 64 : nLen;
        while (m_nBufferSize < nLen)
        {
            m_nBufferSize *= 2;
        }
        //分配新缓冲区
        m_pBuffer = new char[m_nBufferSize];
        memset(m_pBuffer, 0, sizeof(m_pBuffer));
        //将原缓冲区中的内容拷贝到新缓冲区
        memcpy(m_pBuffer, oBuffer, m_nOffset);
        //释放原缓冲区
        delete[]oBuffer;
    }
    /*catch(QException e)
    {
    return false;
    }*/
    return true;
}

//向缓冲区中添加消息
/*
* pBuf，要添加的数据
* nLen，数据长度
* 成功返回true，失败返回false
*/
bool TcpDataProcessor::addMsg(char *pBuf, int nLen)
{
    //try
    {
        if (m_nOffset + nLen > m_nBufferSize)        //如果缓冲过小，重新调整其大小
            reBufferSize(m_nOffset + nLen);
        memcpy(m_pBuffer + m_nOffset, pBuf, nLen); //将新数据拷贝到缓冲区尾
        m_nOffset += nLen;  //修改数据偏移
    }
    /*catch(QException e)
    {
    return false;
    }*/
    return true;
}

//缓冲区复位
void TcpDataProcessor::resetBuffer()
{
    if (m_nOffset > 0)
    {
        memset(m_pBuffer, 0, sizeof(m_pBuffer));
        m_nOffset = 0;
    }
}

//移除缓冲区首部第一个数据包
//nLen：一个数据包的大小
void TcpDataProcessor::poll(int nLen)
{
    if (m_nOffset == 0 || m_pBuffer == NULL)
        return;

    if (m_nOffset >= nLen)
    {
        memcpy(m_pBuffer, m_pBuffer + nLen, m_nOffset - nLen);
        m_nOffset -= nLen;
    }
}
