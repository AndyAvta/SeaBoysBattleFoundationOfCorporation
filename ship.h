#ifndef SHIP_H
#define SHIP_H
#include <QString>

class ship
 {
   unsigned int step;
   int mas[11][11];
   int ship_count;
   int wait_flag;
   bool isai; // Является активным игроком
   int lh_x;
   int lh_y;
   int count;
   int rec_hod;
   QString name;

  public:
   ship();
   friend class pole;

  public:
   void set_isai(bool flag);          // Установка данного поля для компьютера
   bool get_isai();                   // Проверка кому принадлежит поле
   void setmas();                     // Расстановка кораблей
   void setrandom(int i);             // Расстановка кораблей случайным образом
   int atck(int x, int y);            // Метод для атаки корабля
   void ifdesver(int x, int y,int dl);// Проверка уничтожен ли горизонтальный корабль
   void ifdesgor(int x, int y,int dl);// Проверка уничтожен ли вертикальный корабль
   int oprdl(int x, int y,int rot);   // Определение длины корабля
   int rotation(int x,int y);         // Определение вертикальный/горизонтальный корабль
   int prvk(int x, int y);            // Проверка на правильность расстановки корабля
   int valid(int x, int y);           // Проверка на принадлежность клетки полю.
   int getship();                     // Проверка остатка кораблей
   void ship_erase();                 // Удаление кораблей.
   QString get_name();                //Получение имени игрока
   void set_name(QString n_str);
   unsigned int get_step();
   void step_inc();                   // Инкремент номера шага
   int get_lh_x();                    // Последняя координата по x
   int get_lh_y();                    // Последняя координата по y
   int get_hod();                     // Получить ход
 };

#endif                                 // SHIP_H
