#ifndef BYTEARRAYUTIL_H
#define BYTEARRAYUTIL_H

#include <QByteArray>

class ByteArrayUtil
{
public:
    static QByteArray intToByte(int i)
    {
        QByteArray abyte0;
        abyte0.resize(4);
        abyte0[0] = (uchar) (0x000000ff & i);
        abyte0[1] = (uchar) ((0x0000ff00 & i) >> 8);
        abyte0[2] = (uchar) ((0x00ff0000 & i) >> 16);
        abyte0[3] = (uchar) ((0xff000000 & i) >> 24);
        return abyte0;
    }

    static int bytesToInt(QByteArray bytes)
    {
        int addr = bytes[0] & 0x000000FF;
        addr |= ((bytes[1] << 8) & 0x0000FF00);
        addr |= ((bytes[2] << 16) & 0x00FF0000);
        addr |= ((bytes[3] << 24) & 0xFF000000);
        return addr;
    }
};

#endif // BYTEARRAYUTIL_H
