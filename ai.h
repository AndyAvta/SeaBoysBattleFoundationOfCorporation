       #ifndef AI_H
#define AI_H
#include "ship.h"

class ai
 {
  public:
   ai();
   static int ai_1(ship &ship_1);        // аи бьющий рендомом
   static int ai_2(ship &ship_1);        // аи добивающий корабли в который попал, рендом
   static int ai_3(ship &ship_1);        // сложный аи
   static bool if_destr(ship &ship_1);   // Проверка, добит ли корабль.
   static int ai_kill(ship &ship_1);     // метод для добивания кораблей
   static int ai_hkill(ship &ship_1);
 };

#endif                                 // AI_H
