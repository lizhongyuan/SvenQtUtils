#include <QCoreApplication>
#include <src/qttimeutils.h>
#include <src/qregexutils.h>
#include <src/qsqlutils.h>

#include<QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCoreApplication::addLibraryPath("/tmp/");
    qDebug()<<QCoreApplication::libraryPaths();
    //QCoreApplication::addLibraryPath("/home/ganji/Qt5.2.1/5.2.1/gcc_64/plugins/sqldrivers/");
    //QCoreApplication::addLibraryPath("/usr/local/Trolltech/Qt-4.8.6/plugins");

    // 1. example
    /*
    QString curDate = QtTimeUtils::getCurTime("yyyy-MM-dd hh:mm:ss ddd");
    qDebug()<<curDate;
    */

    // 2. example
    /*
    QString regex = QString(" soV=1; expires=Tue, 05-Aug-2014 16:00:00 GMT;soKey=678_347_716; expires=Tue, 05-Aug-2014 16:00:00 GMT;");
    QString pattern = QString("soV.*soKey.*");
    qDebug()<<QRegexUtils::indexIn(regex, pattern);
    */

    // 3. example

    QString confFile = "./conf/conf.ini";
    QSettings* seoSetting = new QSettings(confFile,  QSettings::IniFormat);
    if(seoSetting == NULL)
    {
        qDebug()<<"Where's the seoSetting?";
        return a.exec();
    }

    QSqlUtils mysqlUtil(seoSetting);
    mysqlUtil.connectSql();

    //QString selectStatement = QString::fromStdString("select task_id from distributed_sys_db.distributed_simulator_tbl limit 10");
    //mysqlUtil.selectFromDB(selectStatement);

    /*
    QSqlQuery query;
    query.prepare("select task_id from distributed_sys_db.distributed_simulator_tbl limit 10");
    query.exec();
    while(query.next())
        qDebug()<<query.value(0).toInt();
    */

    //mysqlUtil.selectFromDB("select task_id from distributed_sys_db.distributed_simulator_tbl limit 10");
    mysqlUtil.selectFromDB("select * from distributed_sys_db.distributed_simulator_tbl limit 10");

    qDebug()<<"----------------------";

    return a.exec();
}
