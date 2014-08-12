#ifndef QTTIMEUTILS_H
#define QTTIMEUTILS_H

#include<QString>
#include<QDateTime>

class QtTimeUtils
{
public:
    QtTimeUtils();

    static QString getCurTime(QString pattern);
};

#endif // QTTIMEUTILS_H
