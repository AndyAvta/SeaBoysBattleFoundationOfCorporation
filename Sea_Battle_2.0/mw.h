#ifndef MW_H
#define MW_H
#include "ai.h"
#include "game.h"
#include <QtWidgets/QMainWindow>
#include <QThread>
#include <QtGui>

namespace Ui
 {
  class MWClass;
 }

class MW : public QMainWindow
 {
   Q_OBJECT

   game g1;
   bool i;

  public:
   struct Sleeper : private QThread
    {
     static void msleep(unsigned long msecs)
      {
       QThread::msleep(msecs);
       qApp->processEvents();
      }
    };

   MW(QWidget *parent = 0);
   ~MW();

  private:
   Ui::MWClass *ui;

  private slots:
   void on_p_1_textChanged();                // Левый человек
   void on_p_2_textChanged();                // Правый человек
   void on_cbai_23_clicked(bool checked);    // Сложный правый уровень сложности
   void on_cbai_22_clicked(bool checked);    // Средний правый уровень сложности
   void on_cbai_21_clicked(bool checked);    // Лёгкий правый уровень сложности
   void on_cbai_13_clicked(bool checked);    // Сложный левый уровень сложности
   void on_cbai_12_clicked(bool checked);    // Средний левый уровень сложности
   void on_cbai_11_clicked(bool checked);    // Лёгкий левый уровень сложности
   void on_cbp_1_clicked(bool checked);      // Логин левый
   void on_cbp_2_clicked(bool checked);      // Логин правый
   void on_pushButton_clicked();             // Выйти
   void on_pushButton_2_clicked();           // Рестарт
   void on_pushButton_3_clicked();           // Бой
   void on_pushButton_4_clicked();           // Рекорды
 };

#endif                                 // MW_H
