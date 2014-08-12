#include "qregexutils.h"

QRegexUtils::QRegexUtils()
{
}

/*
QRegexUtils::QRegexUtils(QString regex)
{
    this->setRegex(regex);
}
*/

void
QRegexUtils::setRegex(QString regex)
{
    this->_regex = regex;
}

bool
QRegexUtils::isMatch(QString text)
{
    //QString pattern(".*=.*");
    //QString pattern("<OPTION.*OPTION>");
    //QRegExp rx(pattern);
    QRegExp rx(this->_regex);
    rx.setMinimal(true);    //set to be lazy

    //bool match = rx.exactMatch("a=3");
    bool match = rx.exactMatch(text);
    return match;
}

bool
QRegexUtils::isMatch(QString regex, QString pattern)
{
    QRegExp rx(regex);
    rx.setMinimal(true);

    bool match = rx.exactMatch(pattern);
    return match;
}

int
QRegexUtils::indexIn(QString regex, QString pattern)
{
    QRegExp rx;
    rx.setPattern(pattern);

    return rx.indexIn(regex);
}

/*
bool
isMatch(QString regex, QString pattern)
{
    QRegExp rx(regex);

    bool match = rx.exactMatch(pattern);

    return match;
}
*/
