﻿#include "ship.h"
#include <QApplication>

ship::ship()
 {
  rec_hod=0;
  qsrand(time(NULL));
  lh_x=0;
  lh_y=0;
  count=0;
  for(int i=1;i<=10;i++)
   for (int j=1; j<=10;j++)
    mas[i][j]=0;
 }

void ship::setmas()                    /// Расстановка кораблей
 {
  /// Очистка поля
  for (int i=1; i<=10; i++)
   for (int j=1; j<=10; j++)
    mas[i][j]=0;

  for(int i=1; i<=4 ;i++)              /// Для всех длин кораблей
   for(int j=1; j<=5-i; j++)           /// Для всех кораблей этой длинны
    setrandom(i);                      /// Поставить корабль I длинны
  ship_count=20;
 }

/// Расстановка корабля длинны I случайным образом
void ship::setrandom(int i)
 {
  int cc=0;                               /// Признак "Продолжения установки"

  while(cc==0)                            /// ПОКА Продолжать
   {
    /// Генерация случайных координат
    int x=qrand()%10+1;
    int y=qrand()%10+1;
    if (prvk(x,y)==1)                     /// Координаты допустимы?
      {
       int vert=qrand()%2;                /// Получение случайной ориентации
       int prvk1=0;                       /// Очистка результата проверки
       if (vert==0)                       /// Вертикальны ориентация ?
         {
          for(int j=0;j<=i-1;j++)
           prvk1+=prvk(x,y+j);
          if (prvk1==i)                   /// Хватает свободных клеток?
            /// Заполнить клетки
            for(int k=0;k<=i-1;k++)
             {
              mas[x][y+k]=1;              /// Поставить признаком корабля
              cc=1;                       /// Сбросить признак продолжения
             }
          else
           {
            prvk1=0;                      /// Очистка результата проверки
            for(int j=0;j<=i-1;j++)
             prvk1+=prvk(x,y-j);
            if (prvk1==i)                 /// Хватает свободных клеток?
              /// Заполнить клетки
              for(int k=0;k<=i-1;k++)
               {
                mas[x][y-k]=1;            /// Поставить признаком корабля
                cc=1;                     /// Сбросить признак продолжения
               }
           }
         }
       if (vert==1)                       /// Вертикальной ориентация ?
         {
          prvk1=0;                        /// Очистка результата проверки
          for(int j=0;j<=i-1;j++)
           prvk1+=prvk(x+j,y);
          if (prvk1==i)                   /// Хватает свободных клеток?
            /// Заполнить клетки
            for(int k=0;k<=i-1;k++)
             {
              mas[x+k][y]=1;              /// Поставить признаком корабля
              cc=1;                       /// Сбросить признак продолжения
             }
          else
           {
            prvk1=0;                      /// Очистка результата проверки
            for(int j=0;j<=i-1;j++)
            prvk1+=prvk(x-j,y);
            if (prvk1==i)                 /// Хватает свободных клеток?
             /// Заполнить клетки
             for(int k=0;k<=i-1;k++)
              {
               mas[x-k][y]=1;             /// Поставить признаком корабля
               cc=1;                      /// Сбросить признак продолжения
              }
           }
         }
      }
   }
 }

/// Метод для атаки корабля
int ship::atck(int x, int y)
 {
  int res=0;                              /// Результат Попадание
  if (mas[x][y]==-1 || mas[x][y]==2)      /// Промах или подбита
    res=-1;                               /// В эту клетку уже стреляли
  if (mas[x][y]==1)                       /// Клетка корабля ?
    {
     mas[x][y]=2;                         /// Пометить как подбитыю клетку
     ship_count-=1;                       /// Уменьшить количество цкелых клеток
     lh_x=x;                              /// Память координаты Очистка
     lh_y=y;                              /// Память координаты Очистка
     count++;                             /// Увелечение числа подбитых клеток
     rec_hod++;                           /// Увелечение числа хода
     if (rotation(x,y)==1)                /// Горизонтальный корабль ?
       ifdesver(x,y,oprdl(x,y,1));        /// Пометить как подбитый
     if (rotation(x,y)==2)                /// Вертикальный корабль ?
       ifdesgor(x,y,oprdl(x,y,2));        /// Пометить как подбитый
     if (rotation(x,y)==-1)               /// Одиночный корабль ?
       {
        /// Пометить пространсво вокруг одиночного корабля
        if (valid(x+1,y))                 /// Допустимые координаты клетки ?
          mas[x+1][y]=-1;                 /// Пометить выстрелом
        if (valid(x+1,y+1))               /// Допустимые координаты клетки ?
          mas[x+1][y+1]=-1;               /// Пометить выстрелом
        if (valid(x+1,y-1))               /// Допустимые координаты клетки ?
          mas[x+1][y-1]=-1;               /// Пометить выстрелом
        if (valid(x,y+1))                 /// Допустимые координаты клетки ?
          mas[x][y+1]=-1;                 /// Пометить выстрелом
        if (valid(x,y-1))                 /// Допустимые координаты клетки ?
          mas[x][y-1]=-1;                 /// Пометить выстрелом
        if (valid(x-1,y))                 /// Допустимые координаты клетки ?
          mas[x-1][y]=-1;                 /// Пометить выстрелом
        if (valid(x-1,y-1))               /// Допустимые координаты клетки ?
          mas[x-1][y-1]=-1;               /// Пометить выстрелом
        if (valid(x-1,y+1))               /// Допустимые координаты клетки ?
          mas[x-1][y+1]=-1;               /// Пометить выстрелом
        lh_x=0;                           /// Память координаты Очистка
        lh_y=0;                           /// Память координаты Очистка
        count++;                          /// Увелечение числа подбитых клеток
       }
    }
  if (mas[x][y]==0)                       /// Пустая клетка ?
    {
     mas[x][y]=-1;                        /// Пометить выстрелом
     res=1;                               /// Промах
     count=0;                             /// Число подбитых
     rec_hod++;                           /// Увеличить номер хода
    }
  return res;                             /// если 0 то попадение , если 1 то промах, -1 повторный выстрел
 }
/// определение вертикальный/горизонтальный корабль
int ship::rotation(int x,int y)
 {
  int rot=-1;                             /// единичный корабль
  if (mas[x+1][y]==1||mas[x+1][y]==2||    /// Или сверху непустая клетка
    mas[x-1][y]==1||mas[x-1][y]==2)       /// Или снизу непустая клетка
    rot=1;                                /// Горизонтальный корабль
  if (mas[x][y+1]==1||mas[x][y+1]==2||    /// Или справа непустая клетка
    mas[x][y-1]==1||mas[x][y-1]==2)       /// Или слева непустая клетка
    rot=2;                                /// Вертикальный корабль
  return rot;
 }

/// Проверка уничтожен ли горизонтальный корабль
void ship::ifdesver(int x, int y, int dl) /// dl Длина корабля
 {
  int des=1;
  int x1,x2;
  x1=x;                                   /// абсциса первой клетки корабля
  x2=x;                                   /// абсциса последней клетки корабля
  /// Проверка клеток слева
  if (valid(x-1,y))                       /// Допустимые координаты клетки ?
    if (mas[x-1][y]==2)                   /// Клетка подбита ?
      {
       des+=1;                            /// Учёт подбитых клеток
       x1-=1;                             /// Новая абсциса начала корабля
       if (valid(x-2,y))                  /// Допустимые координаты клетки ?
         if (mas[x-2][y]==2)              /// Клетка подбита ?
           {
            des+=1;                       /// Учёт подбитых клеток
            x1-=1;                        /// Новая абсциса начала корабля
            if (valid(x-3,y))             /// Допустимые координаты клетки ?
              if (mas[x-3][y]==2)         /// Клетка подбита ?
                {
                 des+=1;                  /// Учёт подбитых клеток
                 x1-=1;                   /// Новая абсциса начала корабля
                }
           }
       }
  /// Проверка клеток справа
  if (valid(x+1,y))                       /// Допустимые координаты клетки ?
    if (mas[x+1][y]==2)                   /// Клетка подбита ?
      {
       des+=1;                            /// Учёт подбитых клеток
       x2+=1;                             /// Новая абсциса начала корабля
       if (valid(x+2,y))                  /// Допустимые координаты клетки ?
         if (mas[x+2][y]==2)              /// Клетка подбита ?
           {
            des+=1;                       /// Учёт подбитых клеток
            x2+=1;                        /// Новая абсциса начала корабля
            if (valid(x+3,y))             /// Допустимые координаты клетки ?
              if (mas[x+3][y]==2)         /// Клетка подбита ?
                {
                 des+=1;                  /// Учёт подбитых клеток
                 x2+=1;                   /// Новая абсциса начала корабля
                }
           }
      }
  /// Рамка из точек убитого корабля
  if (des==dl)                            /// Убит?
    {
     if (valid(x1,y+1))                   /// Допустимые координаты клетки ?
       mas[x1][y+1]=-1;                   /// Клетка подбита ?
     if (valid(x1,y-1))                   /// Допустимые координаты клетки ?
       mas[x1][y-1]=-1;                   /// Клетка подбита ?
     if (valid(x1-1,y))                   /// Допустимые координаты клетки ?
       mas[x1-1][y]=-1;                   /// Клетка подбита ?
     if (valid(x1-1,y+1))                 /// Допустимые координаты клетки ?
       mas[x1-1][y+1]=-1;                 /// Клетка подбита ?
     if (valid(x1-1,y-1))                 /// Допустимые координаты клетки ?
       mas[x1-1][y-1]=-1;                 /// Клетка подбита ?
     if (valid(x2,y+1))                   /// Допустимые координаты клетки ?
       mas[x2][y+1]=-1;                   /// Клетка подбита ?
     if (valid(x2,y-1))                   /// Допустимые координаты клетки ?
       mas[x2][y-1]=-1;                   /// Клетка подбита ?
     if (valid(x2+1,y))                   /// Допустимые координаты клетки ?
       mas[x2+1][y]=-1;                   /// Клетка подбита ?
     if (valid(x2+1,y+1))                 /// Допустимые координаты клетки ?
       mas[x2+1][y+1]=-1;                 // Клетка подбита ?
     if (valid(x2+1,y-1))                 /// Допустимые координаты клетки ?
       mas[x2+1][y-1]=-1;                 /// Клетка подбита ?
     lh_x=0;lh_y=0;
     if (des>=3)
       {
        if (valid(x1+1,y+1))              /// Допустимые координаты клетки ?
          mas[x1+1][y+1]=-1;              /// Клетка подбита ?
        if (valid(x1+1,y-1))              /// Допустимые координаты клетки ?
          mas[x1+1][y-1]=-1;              /// Клетка подбита ?
       }
     if (des==4)
       {
        if (valid(x1+2,y+1))              /// Допустимые координаты клетки ?
          mas[x1+2][y+1]=-1;              /// Клетка подбита ?
        if (valid(x1+2,y-1))              /// Допустимые координаты клетки ?
          mas[x1+2][y-1]=-1;              /// Клетка подбита ?
       }
    }

 }
/// проверка уничтожен ли вертикальный корабль
void ship::ifdesgor(int x, int y,int dl)  // dl Длина корабля
 {
  int des=1;
  int y1,y2;
  y1=y;
  y2=y;
  if (valid(x,y-1))                       /// Допустимые координаты клетки ?
    if (mas[x][y-1]==2)                   /// Клетка подбита ?
      {
      des+=1;                             /// Учёт подбитых клеток
      y1-=1;                              /// Новая ордината кормы корабля
      if (valid(x,y-2))                   /// Допустимые координаты клетки ?
        if (mas[x][y-2]==2)               /// Клетка подбита ?
          {
           des+=1;                        /// Учёт подбитых клеток
           y1-=1;                         /// Новая ордината кормы корабля
           if (valid(x,y-3))              /// Допустимые координаты клетки ?
             if (mas[x][y-3]==2)          /// Клетка подбита ?
               {
                des+=1;                   /// Учёт подбитых клеток
                y1-=1;                    /// Новая ордината кормы корабля
               }
          }
      }
  if (valid(x,y+1))                       /// Допустимые координаты клетки ?
    if (mas[x][y+1]==2)                   /// Клетка подбита ?
      {
       des+=1;                            /// Учёт подбитых клеток
       y2+=1;                             /// Новая ордината кормы корабля
       if (valid(x,y+2))                  /// Допустимые координаты клетки ?
         if (mas[x][y+2]==2)              /// Клетка подбита ?
           {
            des+=1;                       /// Учёт подбитых клеток
            y2+=1;                        /// Новая ордината кормы корабля
            if (valid(x,y+3))             /// Допустимые координаты клетки ?
              if (mas[x][y+3]==2)         /// Клетка подбита ?
                {
                 des+=1;                  /// Учёт подбитых клеток
                 y2+=1;                   /// Новая ордината кормы корабля
                }
           }
      }
  if (des==dl)
    {
     if (valid(x,y1-1))                   /// Допустимые координаты клетки ?
       mas[x][y1-1]=-1;                   /// Клетка подбита ?
     if (valid(x-1,y1-1))                 /// Допустимые координаты клетки ?
       mas[x-1][y1-1]=-1;                 /// Клетка подбита ?
     if (valid(x-1,y1))                   /// Допустимые координаты клетки ?
       mas[x-1][y1]=-1;                   /// Клетка подбита ?
     if (valid(x+1,y1))                   /// Допустимые координаты клетки ?
       mas[x+1][y1]=-1;                   /// Клетка подбита ?
     if (valid(x+1,y1-1))                 /// Допустимые координаты клетки ?
       mas[x+1][y1-1]=-1;                 /// Клетка подбита ?
     if (valid(x,y2+1))                   /// Допустимые координаты клетки ?
       mas[x][y2+1]=-1;                   /// Клетка подбита ?
     if (valid(x+1,y2))                   /// Допустимые координаты клетки ?
       mas[x+1][y2]=-1;                   /// Клетка подбита ?
     if (valid(x+1,y2+1))                 /// Допустимые координаты клетки ?
       mas[x+1][y2+1]=-1;                 /// Клетка подбита ?
     if (valid(x-1,y2+1))                 /// Допустимые координаты клетки ?
       mas[x-1][y2+1]=-1;                 /// Клетка подбита ?
     if (valid(x-1,y2))                   /// Допустимые координаты клетки ?
       mas[x-1][y2]=-1;                   /// Клетка подбита ?
     lh_x=0;lh_y=0;
     if (des>=3)
      {
       if (valid(x+1,y1+1))               /// Допустимые координаты клетки ?
         mas[x+1][y1+1]=-1;               /// Клетка подбита ?
       if (valid(x-1,y1+1))               /// Допустимые координаты клетки ?
         mas[x-1][y1+1]=-1;               /// Клетка подбита ?
      }
     if (des==4)
       {
        if (valid(x+1,y1+2))              /// Допустимые координаты клетки ?
          mas[x+1][y1+2]=-1;              /// Клетка подбита ?
        if (valid(x-1,y1+2))              /// Допустимые координаты клетки ?
          mas[x-1][y1+2]=-1;              /// Клетка подбита ?
       }
    }

 }

/// Определение длины корабля
int ship::oprdl(int x, int y,int rot)
 {
  int dl=1;                                          /// Начальная длинна
  /// Проверка корабль справа
  if (rot==1)                                        /// Горизонтальный корабль справа ?
    if (valid(x+1,y))                                /// Допустимые координаты клетки ?
      if (mas[x+1][y]==1 || mas[x+1][y]==2)          /// Занята клетка ?
        {
         dl+=1;                                      /// Увелечение длинны корабля
         if (valid(x+2,y))                           /// Допустимые координаты клетки ?
           if (mas[x+2][y]==1 || mas[x+2][y]==2)     /// Занята клетка ?
             {
              dl+=1;                                 /// Увелечение длинны корабля
              if (valid(x+3,y))                      /// Допустимые координаты клетки ?
                if (mas[x+3][y]==1 || mas[x+3][y]==2)/// Занята клетка ?
                  {
                   dl+=1;
                  }
             }
         }
  /// Проверка корабль слева
  if (rot==1)                                        /// Горизонтальный корабль слева ?
    if (valid(x-1,y))                                /// Допустимые координаты клетки ?
      if (mas[x-1][y]==1 || mas[x-1][y]==2)          /// Занята клетка ?
        {
         dl+=1;                                      /// Увелечение длинны корабля
         if (valid(x-2,y))                           /// Допустимые координаты клетки ?
           if (mas[x-2][y]==1 || mas[x-2][y]==2)     /// Занята клетка ?
             {
              dl+=1;                                 /// Увелечение длинны корабля
              if (valid(x-3,y))                      /// Допустимые координаты клетки ?
                if (mas[x-3][y]==1 || mas[x-3][y]==2)/// Занята клетка ?
                  {
                   dl+=1;                            /// Увелечение длинны корабля
                  }
             }
        }
  /// Проверка корабль сверху
  if (rot==2)                                        /// Вертикальный корабль сверху ?
    if (valid(x,y+1))                                /// Допустимые координаты клетки ?
      if (mas[x][y+1]==1||mas[x][y+1]==2)            /// Занята клетка ?
        {
         dl+=1;                                      /// Увелечение длинны корабля
         if (valid(x,y+2))                           /// Допустимые координаты клетки ?
           if (mas[x][y+2]==1||mas[x][y+2]==2)       /// Занята клетка ?
             {
              dl+=1;                                 /// Увелечение длинны корабля
              if (valid(x,y+3))                      /// Допустимые координаты клетки ?
                if (mas[x][y+3]==1||mas[x][y+3]==2)  /// Занята клетка ?
                  {
                   dl+=1;                             /// Увелечение длинны корабля
                  }
           }
        }
  /// Проверка корабль снизу
  if (rot==2)                                        /// Вертикальный корабль сверху ?
    if (valid(x,y-1))                                /// Допустимые координаты клетки ?
      if (mas[x][y-1]==1||mas[x][y-1]==2)            /// Занята клетка ?
        {
         dl+=1;                                      /// Увелечение длинны корабля
         if (valid(x,y-2))                           /// Допустимые координаты клетки ?
          if (mas[x][y-2]==1||mas[x][y-2]==2)        /// Занята клетка ?
            {
             dl+=1;                                  /// Увелечение длинны корабля
             if (valid(x,y-3))                       /// Допустимые координаты клетки ?
               if (mas[x][y-3]==1||mas[x][y-3]==2)   /// Занята клетка ?
                 {
                  dl+=1;                             /// Увелечение длинны корабля
                 }
            }
        }
  return dl;
 }

/// Проверка на правильность расстановки корабля
int ship::prvk(int x, int y)
 {
  int err=1;                              /// Корабли раставлены неверно
  if (valid(x,y)==1)                      /// Допустимые координаты клетки ?
    {
     if (mas[x][y]==1)                    /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  else
   err=0;                                 /// Корабли раставлены правильно

  if (valid(x+1,y)==1)                    /// Допустимые координаты клетки ?
    {
     if (mas[x+1][y]==1)                  /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x+1,y-1)==1)                  /// Допустимые координаты клетки ?
    {
     if (mas[x+1][y-1]==1)                /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x-1,y+1)==1)                  /// Допустимые координаты клетки ?
    {
     if (mas[x-1][y+1]==1)                /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x,y+1)==1)                    /// Допустимые координаты клетки ?
    {
     if (mas[x][y+1]==1)                  /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x,y-1)==1)                    /// Допустимые координаты клетки ?
    {
     if (mas[x][y-1]==1)                  /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x-1,y)==1)                    /// Допустимые координаты клетки ?
    {
     if (mas[x-1][y]==1)                  /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  if (valid(x-1,y-1)==1)                  /// Допустимые координаты клетки ?
    {
     if (mas[x-1][y-1]==1)                /// Клетка признак дистанции
       err=0;                             ///Корабли раставлены правильно
    }
  if (valid(x+1,y+1)==1)                  /// Допустимые координаты клетки ?
    {
     if (mas[x+1][y+1]==1)                /// Клетка признак дистанции
       err=0;                             /// Корабли раставлены правильно
    }
  return err;
 }

/// Проверка на принадлежность клетки полю.
int ship::valid(int x,int y)

 {
  int i=1;                                /// Координаты клетки допустимы
  if (x<1||x>10)                          /// Выходит за границы по горизонтали ?
    i=0;                                  /// Координаты клетки Недопустимы
  if (y<1||y>10)                          /// Выходит за границы по вертикали ?
    i=0;                                  /// Координаты клетки Недопустимы
  return i;                               /// Результат анализа
 }

/// Проверка остатка кораблей
int ship::getship()
 {
  return ship_count;                      /// Вернуть число не подбитых клеток
 }

/// Проверка кому принадлежит поле
bool ship::get_isai()
 {
  return isai;                            /// Вернуть владельца поля
 }

/// Установка данного поля для компьютера
void ship::set_isai(bool flag)
 {
  isai=flag;                              /// Признак владения поля компьютером
 }

/// Удаление кораблей.
void ship::ship_erase()
 {
  for (int i=0; i<=10; i++)
   for (int j=0; j<=10; j++)
    mas[i][j]=0;                          /// Очистка клетки
  /// Инициализация переменных игры
  step=0;
  ship_count=0;
  lh_x=0;
  lh_y=0;
  count=0;
  rec_hod=0;
 }

///Получение имени игрока
QString ship::get_name()
 {
  return name;
 }

void ship::set_name(QString n_str)
 {
  name=n_str;
 }

unsigned int ship::get_step()
 {
  return step;
 }

/// Инкремент номера шага
void ship::step_inc()
 {
  step++;
 }

/// Последняя координата по x
int ship::get_lh_x()
 {
  return lh_x;
 }

/// Последняя координата по y
int ship::get_lh_y()
 {
  return lh_y;
 }

/// Получить ход
int ship::get_hod()
 {
  return rec_hod;
 }
