#include "qttimeutils.h"

QtTimeUtils::QtTimeUtils()
{
}

QString
QtTimeUtils::getCurTime(QString pattern)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    //QString str = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    QString str = time.toString(pattern); //设置显示格式

    return str;
}
