#ifndef GAME_H
#define GAME_H
#include <QObject>
#include "ship.h"
#include "ai.h"
#include "record.h"


class game: public QObject
 {
   Q_OBJECT
   static record r1;

  public:
   static int hod;
   static bool cbp_1;
   static bool cbp_2;
   static bool cbai_11;
   static bool cbai_12;
   static bool cbai_13;
   static bool cbai_21;
   static bool cbai_22;
   static bool cbai_23;
   static void set_cbp_1(bool flag);
   static void set_cbp_2(bool flag);
   static void set_cbai_11(bool flag);
   static void set_cbai_12(bool flag);
   static void set_cbai_13(bool flag);
   static void set_cbai_21(bool flag);
   static void set_cbai_22(bool flag);
   static void set_cbai_23(bool flag);
   static bool get_cbp_1();
   static bool get_cbp_2();
   static bool get_cbai_11();
   static bool get_cbai_12();
   static bool get_cbai_13();
   static bool get_cbai_21();
   static bool get_cbai_22();
   static bool get_cbai_23();
   static void reset();
   static int if_win(ship &ship_1,ship &ship_2);  /// 0 - Никто не победил,
                                                  /// 1 - Победил ship_2
                                                  /// 2 - Победил ship_1
   ///static void fight(ship &ship_1, ship &ship_2,int x_coord,
   ///                    int y_coord,pole *p);
   /// Передача хода при промахе
   static void p_step(ship &ship_1, ship &ship_2,
                      int x_coord,int y_coord);
   static void set_hod(int i);                    /// Задать, чей ход
   static int get_hod();                          /// Узнать, чей ход

  public slots:
   static int ai_step(ship &ship_1, ship &ship_2);/// Ход активного игрока
 };

#endif   /// GAME_H
