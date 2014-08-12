#ifndef QREGEXUTILS_H
#define QREGEXUTILS_H

#include<QRegExp>
#include<QtDebug>

class QRegexUtils
{
public:
    QRegexUtils();
    //QRegexUtils(QString regex);

    void setRegex(QString regex);

    bool isMatch(QString text);

    static bool isMatch(QString regex, QString pattern);

    static int indexIn(QString regex, QString pattern);
private:
    QString _regex;
};

#endif // QREGEXUTILS_H
