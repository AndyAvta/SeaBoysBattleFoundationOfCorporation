#include "game.h"
#include <QtGui>
#include <QMessageBox>
#include "pole.h"

bool game::cbp_1=0;
bool game::cbp_2=0;
bool game::cbai_11=0;
bool game::cbai_12=0;
bool game::cbai_13=0;
bool game::cbai_21=0;
bool game::cbai_22=0;
bool game::cbai_23=0;
int game::hod=-1;
record game::r1;

void game::reset()
 {
  cbp_1=0;
  cbp_2=0;
  cbai_11=0;
  cbai_12=0;
  cbai_13=0;
  cbai_21=0;
  cbai_22=0;
  cbai_23=0;
 }


void game::set_cbp_1(bool flag)             // Логин левый
 {
  cbp_1=flag;
 }

void game::set_cbp_2(bool flag)             // Логин правый
 {
  cbp_2=flag;
 }

void game::set_cbai_11(bool flag)           // Лёгкий левый уровень сложности
 {
  cbai_11=flag;
 }

void game::set_cbai_12(bool flag)           // Средний левый уровень сложности
 {
  cbai_12=flag;
 }

void game::set_cbai_13(bool flag)           // Сложный левый уровень сложности
 {
  cbai_13=flag;
 }

void game::set_cbai_21(bool flag)           // Лёгкий правый уровень сложности
 {
  cbai_21=flag;
 }

void game::set_cbai_22(bool flag)           // Средний правый уровень сложности
 {
  cbai_22=flag;
 }

void game::set_cbai_23(bool flag)           // Сложный правый уровень сложности
 {
  cbai_23=flag;
 }

bool game::get_cbp_1()                      // Логин левый
 {
  return cbp_1;
 }

bool game::get_cbp_2()                      // Логин правый
 {
  return cbp_2;
 }

bool game::get_cbai_11()                    // Лёгкий левый уровень сложности
 {
  return cbai_11;
 }

bool game::get_cbai_12()                    // Средний левый уровень сложности
 {
  return cbai_12;
 }

bool game::get_cbai_13()                    // Сложный левый уровень сложности
 {
  return cbai_13;
 }

bool game::get_cbai_21()                    // Лёгкий правый уровень сложности
 {
  return cbai_21;
 }

bool game::get_cbai_22()                    // Средний правый уровень сложности
 {
  return cbai_22;
 }

bool game::get_cbai_23()                    // Сложный правый уровень сложности
 {
  return cbai_23;
 }

// Вывод того кто победил
int game::if_win(ship &ship_1,ship &ship_2) 
 {
  QMessageBox msg;
  QString str;
  int ret=0;                                // Никто не победил
  int csh_1;
  int csh_2;
  bool if_ai_1;
  bool if_ai_2;
  csh_1=ship_1.getship();                   // Число кораблей не убитых игроком слева
  csh_2=ship_2.getship();                   // Число кораблей не убитых игроком справа
  if_ai_1=ship_1.get_isai();                // Является активным игроком слева
  if_ai_2=ship_2.get_isai();                // Является активным игроком справа
  if (!csh_1)                               // Игрок слева убил все корабли противника?
    {
     str.setNum(r1.set_rec(ship_2.get_hod(),csh_2,ship_1.get_name()));
     msg.setText(ship_1.get_name()+QString::fromLocal8Bit(" Победил")+QString::fromLocal8Bit(" Счет:")+str);
     msg.exec();
     ret=2;                                 // Победил ship_1
    }
  if (!csh_2)                               // Игрок справа убил все корабли противника?
    {
     str.setNum(r1.set_rec(ship_1.get_hod(),csh_1,ship_2.get_name()));
     msg.setText(ship_2.get_name()+QString::fromLocal8Bit(" Победил")+QString::fromLocal8Bit(" Счет:")+str);
     msg.exec();
     ret=1;                                 // Победил ship_2
    }
  return ret;                               // 0 - Никто не победил, 
                                            // 1 - Победил ship_2
                                            // 2 - Победил ship_1
 }

// Ход активного игрока
int game::ai_step(ship &ship_1, ship &ship_2)
 {
  int ret=1;
  // Анализ возможности передачи хода
  if (hod==1)                               // Ход ship_2?
    {
     if (get_cbai_11())                     // Легкий?
       {
        ret=ai::ai_1(ship_1);
        if (ret==1)
          hod=2;
       }
     if (get_cbai_12())                     // Средний?
       {
        ret=ai::ai_2(ship_1);
        if (ret==1)
          hod=2;
       }
     if (get_cbai_13())                     // Трудный?
       {
        ret=ai::ai_3(ship_1);
        if (ret==1)
          hod=2;
       }
    }

  // Анализ возможности передачи хода
  if (hod==2)                               // Ход ship_1?
    {
     if (get_cbai_21())                     // Легкий?
       {
        ret=ai::ai_1(ship_2);
        if (ret==1)
          hod=1;
       }
     if (get_cbai_22())                     // Средний?
       {
        ret=ai::ai_2(ship_2);
        if (ret==1)
          hod=1;
       }
     if (get_cbai_23())                     // Трудный?
       {
        ret=ai::ai_3(ship_2);
        if (ret==1)
          hod=1;
       }
    }
  return ret;
 }

// Передача хода при промахе
void game::p_step(ship &ship_1,ship &ship_2,int x_coord,int y_coord)
 {
  int r=0;                                                        // Считаем, что попал
  if (hod==1)                                                     // Ход игрока 1?
    {
     if (y_coord>0 && y_coord<=10 && x_coord>0 && x_coord<=10 &&  // Клетка в поле И
         get_cbp_1())                                             // ходит cbp_1?
       {
        ship_1.step_inc();                                        // Увеличить число ходов
        r=ship_1.atck(x_coord,y_coord);                           // Результат атаки
        if (r==1)                                                 // Промах?
          {
           hod=2;                                                 // Передать ход игроку 2
          }
       }
    }

  if (hod==2)                                                     // Ход игрока 2?
    {
     if (y_coord>0 && y_coord<=10 && x_coord>12 && x_coord<=22 && // Клетка в поле И
         get_cbp_2())                                             // ходит cbp_2?
       {
        r=ship_2.atck(x_coord-12,y_coord);                        // Результат атаки
        ship_1.step_inc();                                        // Увеличить номер хода
        if (r==1)                                                 // Промах?
          {
           hod=1;                                                 // Передать ход игроку 1
          }
       }
    }
 }

// Задать номер хода
void game::set_hod(int i)
 {
  hod=i;
 }

// Прочитать номер хода
int game::get_hod()
 {
  return hod;
 }
