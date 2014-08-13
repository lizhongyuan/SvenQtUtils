#include "qcharsetutils.h"

QCharSetUtils::QCharSetUtils()
{
}

void
QCharSetUtils::SetCharset()
{
  // 设置全局字符编码为UTF-8
  QTextCodec *codec = QTextCodec::codecForName("UTF-8");
  QTextCodec::setCodecForLocale(codec);
  QTextCodec::setCodecForCStrings(codec);
  QTextCodec::setCodecForTr(codec);
}
