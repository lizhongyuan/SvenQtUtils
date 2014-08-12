#include <QCoreApplication>
#include <src/qttimeutils.h>
#include <src/qregexutils.h>

#include<QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
    QString curDate = QtTimeUtils::getCurTime("yyyy-MM-dd hh:mm:ss ddd");
    qDebug()<<curDate;
    */

    QString regex = QString(" soV=1; expires=Tue, 05-Aug-2014 16:00:00 GMT;soKey=678_347_716; expires=Tue, 05-Aug-2014 16:00:00 GMT;");
    QString pattern = QString("soV.*soKey.*");
    //QString regex = QString(".*2014.*");


    qDebug()<<QRegexUtils::indexIn(regex, pattern);
    /*
    if(QRegexUtils::isMatch(regex, pattern))
    {
        qDebug()<<"match.";
    }
    */

    return a.exec();
}
