#ifndef TEST_H
#define TEST_H

#include <QTest>
#include <QObject>
#include "ai.h"
#include <QFrame>
#include <QtGui>
#include <record.h>
#include "mw.h"
#include <qtextcodec.h>

class Test: public QObject
 {
  Q_OBJECT

  private:
   bool Condition()
    {
     return true;
    }
  private slots:
   void initTestCase()
    {
     qDebug("Запуск тестов...");
    }
   void FirstTest()
    {
     QVERIFY(Condition());
     QCOMPARE(10, 10);
    }
   void SecondTest()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
 };
#endif // TEST_H
