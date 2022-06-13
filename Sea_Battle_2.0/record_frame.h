#ifndef RECORD_FRAME_H
#define RECORD_FRAME_H
#include <QFrame>
#include <QtGui>
#include <record.h>

namespace Ui
 {
  class record_frame;
 }

class record_frame : public QFrame
 {
   Q_OBJECT
   Q_DISABLE_COPY(record_frame)

  public:
   record tab;
   explicit record_frame(QWidget *parent = 0);
   virtual ~record_frame();
   void paintEvent(QPaintEvent *p);

  protected:
   virtual void changeEvent(QEvent *e);

  private:
   Ui::record_frame *m_ui;
 };

#endif                                 // RECORD_FRAME_H
