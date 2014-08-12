#include "qcookie.h"

QCookie::QCookie()
{
}

QCookie::~QCookie()
{
}

QList<QNetworkCookie>
QCookie::getCookies()
{
    return allCookies();
}

void
QCookie::setCookies(const QList<QNetworkCookie>& cookieList)
{
    if(this == NULL)
        return;
    this->setAllCookies(cookieList);
}
