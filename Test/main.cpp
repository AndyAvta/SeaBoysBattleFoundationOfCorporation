#ifndef TEST_H
#define TEST_H

#include <QTest>
#include <QObject>
#include "Sea_Battle_2.0\ai.h"
#include "Sea_Battle_2.0\game.h"
#include <QFrame>
#include <QtGui>
#include <Sea_Battle_2.0\record.h>
#include "Sea_Battle_2.0\mw.h"
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
   void cbp_1_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
     QCOMPARE(9, 9);
    }
   void cbp_2_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
     QCOMPARE(6, 6);
    }
   void cbai_11_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
   void cbai_12_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
   void cbai_13_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
   void cbai_21_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
   void cbai_22_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
   void cbai_23_Test()
    {
     QVERIFY(Condition());
     QVERIFY(1==1);
    }
 };
#endif // TEST_H
