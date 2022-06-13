#include "record.h"
record::record()
 {
  QString st;
  QFile file("winners.dat");

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    return;

  QTextStream in(&file);

  for (int i=1; i<11; i++)
   //in << i<< "unknown"<<endl;
   in >> rec[i] >> str[i];
  file.close();
 }

void record::bubble()
 {
  int c=1;

  while(c!=0)
   {
    c=0;
    for(int i=1; i<=10; i++)
     {
      if (rec[i]<rec[i+1])
        {
         int tmp=rec[i];
         rec[i]=rec[i+1];
         rec[i+1]=tmp;
         QString tmps=str[i];
         str[i]=str[i+1];
         str[i+1]=tmps;
         c++;
        }
     }
   }
 }

void record::save()
 {
  QFile file("winners.dat");

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    return;
  QTextStream out(&file);
  for(int i=1; i<11; i++)
   out << rec[i] << str[i]<<endl;
  //out << rec[i]<< str[i];;//<<endl;
  file.close();
 }

void record::reload()
 {
  QString st;
  QFile file("winners.dat");

  if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    return;

  QTextStream in(&file);

  for(int i=1; i<11; i++)
   in >> rec[i]  >> str[i];
  file.close();
 }

int record::set_rec(int step_n, int ship_e, QString name)
 {
  int i=(100-step_n)*ship_e;
  rec[11]=i;
  //str[1]=name;
  str[11]=name;
  //QString::fromLocal8Bit("known");
  bubble();
  save();
  return i;
 }
