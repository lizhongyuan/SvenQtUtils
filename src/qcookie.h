#ifndef QCOOKIE_H
#define QCOOKIE_H

#include<QtNetwork/QNetworkCookieJar>
#include<QtNetwork/QNetworkCookie>


class QCookie: public QNetworkCookieJar
{
public:
    QCookie();
    ~QCookie();

    QList<QNetworkCookie> getCookies();

    void
    setCookies(const QList<QNetworkCookie>& cookieList);
};

#endif // QCOOKIE_H
