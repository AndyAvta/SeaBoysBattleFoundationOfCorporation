#ifndef POLE_H
#define POLE_H
#include "ship.h"
#include "game.h"
#include <QFrame>
#include <QGraphicsEllipseItem>

namespace Ui
 {
  class pole;
 }

class pole : public QFrame
 {
   Q_OBJECT
   Q_DISABLE_COPY(pole)
   QGraphicsEllipseItem item;
   int xrast;
   int xcord;
   int ycord;
   int xmas;
   game g1;
   int ymas;
   int cc;

  public:
   int stop;
   ship ship_1;
   ship ship_2;
   explicit pole(QWidget *parent = 0);
   virtual ~pole();
   void paintEvent(QPaintEvent *p);
   void paintpole(QPainter &painter);  /// прорисовка поля
   void shipevent1(QPainter &painter); /// прорисовка кораблей игрока для поля 1
   void shipevent2(QPainter &painter); /// прорисовка кораблей компьютера для поля 1
   void shipevent3(QPainter &painter); /// прорисовка кораблей игрока для поля 2
   void shipevent4(QPainter &painter); /// прорисовка кораблей компьютера для поля 2
   void mousePressEvent(QMouseEvent *qmep);/// перегрузка метода нажатия мыши
   void pcvpc(ship &ship_1,ship &ship_2);

  protected:
   virtual void changeEvent(QEvent *e);

  private:
   Ui::pole *m_ui;

  public slots:
   void ppstep();
   void pvpc();
   void ai_step();
   ///void p_step(ship &ship_1,ship &ship_2,int x_coord,int y_coord);
 };

#endif                                 /// POLE_H
