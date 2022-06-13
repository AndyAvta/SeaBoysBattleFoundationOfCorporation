#include <QApplication>
#include "mw.h"
#include <qtextcodec.h>

int main(int argc, char *argv[])
 {
  QApplication a(argc, argv);
  QTextCodec *codec;
                                       //codec=QTextCodec::codecForName("Windows-1251");
  codec=QTextCodec::codecForName("UTF-8");
                                       //QTextCodec::setCodecForCStrings(codec);
  QTextCodec::setCodecForLocale(codec);
                                       //QTextCodec::setCodecForTr(codec);
  MW w;
  w.show();
  return a.exec();
 }
