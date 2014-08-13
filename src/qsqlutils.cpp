#include "qsqlutils.h"

QSqlUtils::QSqlUtils()
{
}

QSqlUtils::QSqlUtils(QSettings* sqlConf)
{
    setSqlConf(sqlConf);
}

bool
QSqlUtils::connectSql()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    /*
    db.setHostName("127.0.0.1");
    db.setDatabaseName("cookies");
    db.setUserName("root");
    db.setPassword("posky314");
    */

    QString hostName = _sqlConf->value("db/host").toString();
    QString dbName = _sqlConf->value("db/dbname").toString();
    QString userName = _sqlConf->value("db/user").toString();
    QString passwd = _sqlConf->value("db/passwd").toString();
    int port = _sqlConf->value("db/port").toInt();

    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(userName);
    db.setPassword(passwd);
    db.setPort(port);


    if(db.open())
    {
        qDebug()<<"OK in connecting DB.";
        return true;
    }
    else
    {
        qDebug()<<"Failed in connecting DB.";
        return false;
    }
}

void
QSqlUtils::insertDB(QString cookieStr)
{
    QString insertSql = "insert into baidu_cookie (baidu_cookie, create_time, update_time)"
                        "values('" + cookieStr + "', now(), now() )";
    QSqlQuery query;
    query.exec(insertSql);
}

QList<QList<QVariant> >
QSqlUtils::selectFromDB(const QString& selectStatement)
{
    QList<QList<QVariant> > selContList;

    QSqlQuery query;
    query.exec(selectStatement);
    const int memCount = query.record().count();

    while(query.next())
    {
        QList<QVariant> curQueryList;
        for(int i = 0; i < memCount; i++)
        {
            curQueryList.push_back(query.value(i));
        }
        qDebug()<<"cur curQueryList size is "<<curQueryList.size();
        selContList.push_back(curQueryList);
    }

    qDebug()<<"selContList size:"<<selContList.size();

    return selContList;
}

QSettings*
QSqlUtils::sqlConf() const
{
    return _sqlConf;
}

void
QSqlUtils::setSqlConf(QSettings *sqlConf)
{
    _sqlConf = sqlConf;
}


