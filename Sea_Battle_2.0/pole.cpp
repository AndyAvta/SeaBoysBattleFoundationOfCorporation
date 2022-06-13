#include "pole.h"
#include "ui_pole.h"
#include "mw.h"
#include "ui_mw.h"
#include "ai.h"
#include "QWidget"
#include "QFrame"
#include "QPainter"

pole::pole(QWidget *parent) :
    QFrame(parent),
    m_ui(new Ui::pole)
 {
  pole::setDisabled(1);
  m_ui->setupUi(this);
  xrast=240;
  srand(time(NULL));
  cc=0;
  stop=0;
 }

pole::~pole()
 {
  delete m_ui;
 }

// перегрузка метода нажатия мыши
void pole::mousePressEvent(QMouseEvent *qmep)
 {
  QPainter p;
  xcord=qmep->x();
  ycord=qmep->y();
  xmas=xcord/20;
  ymas=ycord/20;
  update();
  if (game::if_win(ship_1,ship_2)==0)
    {
     if (game::get_cbp_1()==1 && game::get_cbp_2()==1)
       game::p_step(ship_1,ship_2,xmas,ymas);
     if ((game::get_cbp_1()==0 && game::get_cbp_2()==1 && game::hod==2) ||
       (game::get_cbp_1()==1 && game::get_cbp_2()==0 && game::hod==1))
       game::p_step(ship_1,ship_2,xmas,ymas);
     if ((game::get_cbp_1()==0 && game::get_cbp_2()==1 && game::hod==1) ||
       (game::get_cbp_1()==1 && game::get_cbp_2()==0 && game::hod==2))
       {
        pvpc();
       }
    }
  if (game::if_win(ship_1,ship_2)==1)
    pole::setDisabled(1);
  update();
 }

void pole::changeEvent(QEvent *e)
 {
  switch (e->type())
   {
    case QEvent::LanguageChange:
     m_ui->retranslateUi(this);
    break;
    default:
    break;
   }
 }

void pole::paintEvent(QPaintEvent *p)
 {
  QPainter painter(this);
  paintpole(painter);
  if (game::get_cbp_1())
     shipevent2(painter);
  if (game::get_cbai_11() || game::get_cbai_12() || game::get_cbai_13())
     shipevent1(painter);
  if (game::get_cbp_2())
     shipevent4(painter);
  if (game::get_cbai_21() || game::get_cbai_22() || game::get_cbai_23())
     shipevent3(painter);
 }

// прорисовка кораблей игрока для поля 1
void pole::shipevent1(QPainter &painter)
 {
  for (int xc=1;xc<=10;xc++)
   for (int yc=1;yc<=10;yc++)
    {
     if (ship_1.mas[xc][yc]>=1)                            // Клетка корабля ?
       painter.fillRect(xc*20+1,yc*20+1,19,19,Qt::gray);   // Закрасить серым
     if (ship_1.mas[xc][yc]==-1)                           // Промах ?
       painter.fillRect(xc*20+9,yc*20+9,5,5,Qt::black);    // пометка клетки чёрным квадратиком
     if (ship_1.mas[xc][yc]==2)                            // Подбит ?
       {
        // Рисование крестика
        painter.drawLine(xc*20,yc*20,(xc+1)*20,(yc+1)*20);
        painter.drawLine((xc+1)*20,yc*20,(xc)*20,(yc+1)*20);
       }
    }
 }

// прорисовка кораблей компьютера для поля 1
void pole::shipevent2(QPainter &painter)
 {
  for (int xc=1; xc<=10; xc++)
   for (int yc=1; yc<=10; yc++)
    {
     if (ship_1.mas[xc][yc]==-1)                           // Промах ?
       painter.fillRect(xc*20+9,yc*20+9,5,5,Qt::black);    // пометка клетки чёрным квадратиком
     if (ship_1.mas[xc][yc]==2)                            // Подбит ?
       {
        painter.fillRect(xc*20+1,yc*20+1,19,19,Qt::gray);  // Закрасить серым квадрат корабля
        // Рисование крестика
        painter.drawLine(xc*20,yc*20,(xc+1)*20,(yc+1)*20);
        painter.drawLine((xc+1)*20,yc*20,(xc)*20,(yc+1)*20);
       }
    }
 }

// прорисовка кораблей игрока для поля 2
void pole::shipevent3(QPainter &painter)
 {
  for (int xc=1; xc<=10; xc++)
   for (int yc=1; yc<=10; yc++)
    {
     if (ship_2.mas[xc][yc]>=1)                                         // Клетка корабля ?
       painter.fillRect(xc*20+1+xrast,yc*20+1,19,19,Qt::gray);          // Закрасить серым
     if (ship_2.mas[xc][yc]==-1)                                        // Промах ?
       painter.fillRect(xc*20+9+xrast,yc*20+9,5,5,Qt::black);           // пометка клетки чёрным квадратиком
     if (ship_2.mas[xc][yc]==2)                                         // Подбит ?
       {
        // Рисование крестика
        painter.drawLine(xc*20+xrast,yc*20,(xc+1)*20+xrast,(yc+1)*20);
        painter.drawLine((xc+1)*20+xrast,yc*20,(xc)*20+xrast,(yc+1)*20);
       }
    }
 }

// прорисовка кораблей компьютера для поля 2
void pole::shipevent4(QPainter &painter)
 {
  for (int xc=1; xc<=10; xc++)
   for (int yc=1; yc<=10; yc++)
    {
     if (ship_2.mas[xc][yc]==-1)                                        // Промах ?
       painter.fillRect(xc*20+9+xrast,yc*20+9,5,5,Qt::black);           // пометка клетки чёрным квадратиком
     if (ship_2.mas[xc][yc]==2)                                         // Подбит ?
       {
        painter.fillRect(xc*20+1+xrast,yc*20+1,19,19,Qt::gray);         // Закрасить серым квадрат корабля
        // Рисование крестика
        painter.drawLine(xc*20+xrast,yc*20,(xc+1)*20+xrast,(yc+1)*20);
        painter.drawLine((xc+1)*20+xrast,yc*20,(xc)*20+xrast,(yc+1)*20);
       }
    }
 }

// Прорисовка поля
void pole::paintpole(QPainter &painter)
 {
  painter.setPen(Qt::black);
  painter.setFont(QFont("Arial", 12));
  int Xpl=20;
  QString ch;
  painter.fillRect(0,0,Xpl*11,Xpl*11, Qt::white);           // очистка левого поля белом цветом
  painter.fillRect(0+xrast,0,xrast-Xpl,Xpl*11, Qt::white);  // очистка правого поля белом цветом
  for (int i=1; i<11; i++)                                    // для всех строк поля
   {
    ch.setNum(i);                                           // перевод i в строку
    painter.drawText(1,Xpl*(i+1)-1,ch);                     // простановка номера строки левого поля
    painter.drawText(1+xrast,Xpl*(i+1)-1,ch);               // простановка номера строки правого поля
   }
  // Прорисовка сетки
  for (int i=0; i<=Xpl*11; i+=Xpl)
   {
    painter.drawLine(i, 0, i, Xpl*11);                     // x0 y0 x y Вертикальная I-тая линия левого поля
    painter.drawLine(0,i,Xpl*11,i);                        // Горизонтальная I-тая линия левого поля
    painter.drawLine(i+xrast, 0, i+xrast, Xpl*11);         // x0 y0 x y Вертикальная I-тая линия правого поля
    painter.drawLine(0+xrast,i,Xpl*11+xrast,i);            // Горизонтальная I-тая линия правого поля
   }
  // Заголовки столбцов левого поля
  painter.drawText(Xpl*1+1,Xpl-1,QString::fromLocal8Bit("а"));
  painter.drawText(Xpl*2+1,Xpl-1,QString::fromLocal8Bit("б"));
  painter.drawText(Xpl*3+1,Xpl-1,QString::fromLocal8Bit("в"));
  painter.drawText(Xpl*4+1,Xpl-1,QString::fromLocal8Bit("г"));
  painter.drawText(Xpl*5+1,Xpl-1,QString::fromLocal8Bit("д"));
  painter.drawText(Xpl*6+1,Xpl-1,QString::fromLocal8Bit("е"));
  painter.drawText(Xpl*7+1,Xpl-1,QString::fromLocal8Bit("ж"));
  painter.drawText(Xpl*8+1,Xpl-1,QString::fromLocal8Bit("з"));
  painter.drawText(Xpl*9+1,Xpl-1,QString::fromLocal8Bit("и"));
  painter.drawText(Xpl*10+1,Xpl-1,QString::fromLocal8Bit("к"));
  // Заголовки столбцов правого поля
  painter.drawText(Xpl*1+1+xrast,Xpl-1,QString::fromLocal8Bit("а"));
  painter.drawText(Xpl*2+1+xrast,Xpl-1,QString::fromLocal8Bit("б"));
  painter.drawText(Xpl*3+1+xrast,Xpl-1,QString::fromLocal8Bit("в"));
  painter.drawText(Xpl*4+1+xrast,Xpl-1,QString::fromLocal8Bit("г"));
  painter.drawText(Xpl*5+1+xrast,Xpl-1,QString::fromLocal8Bit("д"));
  painter.drawText(Xpl*6+1+xrast,Xpl-1,QString::fromLocal8Bit("е"));
  painter.drawText(Xpl*7+1+xrast,Xpl-1,QString::fromLocal8Bit("ж"));
  painter.drawText(Xpl*8+1+xrast,Xpl-1,QString::fromLocal8Bit("з"));
  painter.drawText(Xpl*9+1+xrast,Xpl-1,QString::fromLocal8Bit("и"));
  painter.drawText(Xpl*10+1+xrast,Xpl-1,QString::fromLocal8Bit("к"));
 }

void pole::ppstep()
 {
  int air;
  pole::setEnabled(0);

  if (stop!=1)
    air=game::ai_step(ship_1, ship_2);
  update();
  if (stop!=1)
    if (air!=1)
      QTimer::singleShot(700, this,  SLOT(ppstep()));
  pole::setEnabled(1);
 }

void pole::pcvpc(ship &ship_1, ship &ship_2)
 {
  update();
  if (stop!=1)
    if (game::if_win(ship_1, ship_2)==0)
      if (stop!=1)
        QTimer::singleShot(700, this,  SLOT(ai_step()));
        update();
  }

void pole::pvpc()
 {
  pole::setDisabled(1);                                          // Скрыть поле
  update();
  if (game::if_win(ship_1, ship_2)==0)                           // 
    {
     if (stop!=1)                                                // Не стоп?
       {
        if ((game::get_cbp_2()==0 && game::hod==2) ||            //
            (game::get_cbp_1()==0 && game::hod==1))              //
          {
           if (game::if_win(ship_1,ship_2)==0)
             {
              QTimer::singleShot(700, this, SLOT(ai_step()));    // 
             }
           else pole::setEnabled(1);                             // Показать поле
          }
         else pole::setEnabled(1);                               // Показать поле
       }
      else pole::setEnabled(1);                                  // Показать поле
    }
  update();
 }

void pole::ai_step()
 {
  if (stop!=1)
    {
     int ret=1;
     pole::setEnabled(1);
     if (game::hod==1 && game::if_win(ship_1,ship_2)==0)
       {
        if (game::get_cbai_11())
          {
           ret=ai::ai_1(ship_1);
           if (ret==1)
             game::hod=2;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
             return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
           return pvpc();
          }
        if (game::get_cbai_12())
          {
           ret=ai::ai_2(ship_1);
           if (ret==1)
             game::hod=2;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
             return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
             return pvpc();
          }
        if (game::get_cbai_13())
          {
           ret=ai::ai_3(ship_1);
           if (ret==1)
             game::hod=2;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
             return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
             return pvpc();
          }
       }
     if (game::hod==2)
       {
        if (game::get_cbai_21())
          {
           ret=ai::ai_1(ship_2);
           if (ret==1)
             game::hod=1;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
            return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
             return pvpc();
          }
        if (game::get_cbai_22())
          {
           ret=ai::ai_2(ship_2);
           if (ret==1)
             game::hod=1;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
             return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
             return pvpc();
          }
        if (game::get_cbai_23())
          {
           ret=ai::ai_3(ship_2);
           if (ret==1)
             game::hod=1;
           if (game::get_cbp_1()==0 && game::get_cbp_2()==0)
             return pcvpc(ship_1,ship_2);
           if ((game::get_cbp_1()==0 && game::get_cbp_2()==1)  ||
             (game::get_cbp_1()==1 && game::get_cbp_2()==0))
             return pvpc();
          }
       }
    }
 }
