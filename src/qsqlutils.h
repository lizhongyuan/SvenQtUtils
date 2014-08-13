#ifndef QSQLUTILS_H
#define QSQLUTILS_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QDebug>
#include <QSettings>


class QSqlUtils
{
public:
    QSqlUtils();
    QSqlUtils(QSettings* sqlConf);

    /*
    QSqlUtils(QString host,
              QString username,
              QString passwd,
              QString dbname);*/

    bool
    connectSql();

    void
    insertDB(QString cookieStr);

    QList<QList<QVariant> >
    selectFromDB(const QString& selectStatement);

    QSettings*
    sqlConf() const;

    void
    setSqlConf(QSettings *sqlConf);
private:
    QSettings* _sqlConf;
};

#endif // QSQLUTILS_H
