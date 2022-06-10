#include "ai.h"
#include <QApplication>
ai::ai()
{
 qsrand(time(NULL));
}

int ai::ai_1(ship  & ship_1)           // аи бьющий рендомом
 {
  int air=-1;

  while (air==-1)
   {
    int x=qrand()%10+1;
    int y=qrand()%10+1;
      air=ship_1.atck(x,y);

    if (ship_1.getship()==0)air=5;
      ship_1.step_inc();
    }
  return air;
 }

int ai::ai_2(ship  & ship_1)           // аи добивающий корабли в который попал, рендом
 {
  int air=-1;

  while (air==-1)
   {
    if (ship_1.getship()==0)air++;
    int x=qrand()%10+1;
    int y=qrand()%10+1;
    if (air==-1)
      if (!if_destr(ship_1))
        {
         air=ship_1.atck(x,y);
        }
    if (air==-1)
      if (if_destr(ship_1))
        {
         air=ai_kill(ship_1);
        }
    }
                                       //ship_1.step_inc();
  return air;
 }

int ai::ai_3(ship & ship_1)            // сложный аи
 {
  int air=-1;

  while (air==-1)
   {
    if (ship_1.getship()==0)
      air++;
    int x=qrand()%10+1;
    int y=qrand()%10+1;
    if (air==-1)
      if (!if_destr(ship_1))
        {
         air=ship_1.atck(x,y);
        }
     if (air==-1)
       if (if_destr(ship_1))
         {
          air=ai_hkill(ship_1);
         }
   }
                                        //  ship_1.step_inc();
  return air;
 }

bool ai::if_destr(ship  & ship_1)      // Проверка, добит ли корабль.
 {
 bool ret=false;
 if (ship_1.get_lh_x()!=0 && ship_1.get_lh_y()!=0)
   ret=true;
 return ret;
 }

int ai::ai_kill(ship  & ship_1)        // метод для добивания кораблей
 {
  int x;
  int c1;
  int c2;
  int xl=ship_1.get_lh_x();
  int yl=ship_1.get_lh_y();
  int air=-1;

  while (air==-1)
   {
    int rot=qrand()%2+1;
    if (rot==1)                        // горизонтальный корабль?
      {
       x=qrand()%2;
       if (x==0)
         {
          c1=1; c2=-1;
         }
       if (x==1)
         {
          c1=-1; c2=1;
         }

       while (air==-1  &  qAbs(c1)<4  &  qAbs(c2)<4)
        {
         if (ship_1.valid(xl+c1,yl))
          air=ship_1.atck(xl+c1,yl);

         if (ship_1.valid(xl+c2,yl))
           if (air==-1)
             air=ship_1.atck(xl+c2,yl);
         if (c1<0)
           {
            c1-=1; c2+=1;
           }
         if (c1>0)
           {
           c1+=1; c2-=1;
           }
        }
     }

    if (rot==2)                        // вертикальный корабль?
      {
       air=-1;
       x=qrand()%2;
       if (x==0)
         {
          c1=1; c2=-1;
         }
       if (x==1)
         {
          c1=-1; c2=1;
         }

       while (air==-1 & qAbs(c1)<4 & qAbs(c2)<4)
        {
         if (ship_1.valid(xl,yl+c1))
           air=ship_1.atck(xl,yl+c1);
         if (ship_1.valid(xl,yl+c2))
          if (air==-1)
            air=ship_1.atck(xl,yl+c2);
         if (c1<0)
           {
            c1-=1; c2+=1;
           }
         if (c1>0)
           {
            c1+=1; c2-=1;
           }
        }
      }
   }
  return air;
 }

int ai::ai_hkill(ship  & ship_1)
 {
  int x;
  int c1;
  int c2;
  int xl=ship_1.get_lh_x();
  int yl=ship_1.get_lh_y();
  int air=-1;
  int rot=ship_1.rotation(ship_1.get_lh_x(),ship_1.get_lh_y());

  if (rot==1)                          // горизонтальный корабль
    {
     x=qrand()%2;
     if (x==0)
       {
        c1=1; c2=-1;
       }
     if (x==1)
       {
        c1=-1; c2=1;
       }

     while (air==-1 & qAbs(c1)<4 & qAbs(c2)<4)
      {
       if (ship_1.valid(xl+c1,yl)) air=ship_1.atck(xl+c1,yl);
       if (ship_1.valid(xl+c2,yl))
         if (air==-1)
           air=ship_1.atck(xl+c2,yl);
       if (c1<0)
         {
          c1-=1; c2+=1;
         }
       if (c1>0)
         {
          c1+=1; c2-=1;
         }
      }
    }

  if (rot==2)                          // вертикальный корабль
    {
     air=-1;
     x=qrand()%2;
     if (x==0)
       {
        c1=1; c2=-1;
       }
     if (x==1)
       {
        c1=-1; c2=1;
       }

     while (air==-1 & qAbs(c1)<4 & qAbs(c2)<4)
      {
       if (ship_1.valid(xl,yl+c1))
         air=ship_1.atck(xl,yl+c1);
       if (ship_1.valid(xl,yl+c2))
         if (air==-1)
           air=ship_1.atck(xl,yl+c2);
       if (c1<0)
         {
          c1-=1; c2+=1;
         }
       if (c1>0)
         {
          c1+=1; c2-=1;
         }
      }
    }
  return air;
 }

