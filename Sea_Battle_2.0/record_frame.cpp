#include "record_frame.h"
#include "ui_record_frame.h"


record_frame::record_frame(QWidget *parent) :
 QFrame(parent),
 m_ui(new Ui::record_frame)
  {
   m_ui->setupUi(this);
   this->setVisible(0);
  }

void record_frame::paintEvent(QPaintEvent *p)
 {
  QPainter painter(this);
  QString str;
  painter.fillRect(200,0,200,220,Qt::white);
  painter.drawLine(300,0,300,220);
  painter.drawLine(200,0,200,220);
  painter.drawLine(400,0,400,220);
  painter.drawText(205,15,QString::fromLocal8Bit("игрок"));
  for(int i=0; i<12; i++)
   painter.drawLine(200,i*20,400,i*20);
  for(int i=1; i<11 ;i++)
   {
    painter.drawText(205,i*20+15,tab.str[i]);
    painter.drawText(305,i*20+15,str.setNum(tab.rec[i]));
   }
  painter.drawText(305,15,QString::fromLocal8Bit("счет"));
 }

record_frame::~record_frame()
 {
  delete m_ui;
 }

void record_frame::changeEvent(QEvent *e)
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
