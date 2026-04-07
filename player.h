#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>

// 8x8, 1 frame(s), 8 bytes
// Example: Arduboy2Base::drawBitmap(x, y, face, 8, 8, WHITE);
const uint8_t PROGMEM face[] = {
  0x7e, 0xff, 0xd3, 0xbf, 0xbf, 0xd3, 0xff, 0x7e,
};

class Player {
  private:
    Arduboy2 *ab;
    uint8_t x = 100;
    uint8_t y = 30;
  
  public:
    Player(Arduboy2 *ab_ptr) : ab(ab_ptr) {}

    void update() {
      if (ab->pressed(LEFT_BUTTON)) {
        x--;
      }
      if (ab->pressed(RIGHT_BUTTON)) {
        x++;
      }
      if (ab->pressed(UP_BUTTON)) {
        y--;
      }
      if (ab->pressed(DOWN_BUTTON)) {
        y++;
      }
    }

    void draw() {
      ab->drawBitmap(x, y, face, 8, 8, WHITE);
    }
};

#endif