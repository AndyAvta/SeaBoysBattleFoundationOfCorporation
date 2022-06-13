#ifndef RECORD_H
#define RECORD_H
#include <QString>
#include <QFile>
#include <QTextStream>

class record
 {
  QFile file;

  private:

  public:
   int rec[12];
   QString str[12];

   record();
   void bubble();
   void save();
   void reload();
   int set_rec(int step_n,int ship_e,QString name);
 };

#endif                                 // RECORD_H
