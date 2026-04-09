#ifndef MEDAL_H
#define MEDAL_H

#include <Arduboy2.h>

// 8x8, 1 frame(s)
// Image: 10 bytes, Mask: 8 bytes
// Example: Sprites::drawExternalMask(x, y, star, starMask, frame, 0);
const uint8_t PROGMEM star[] = {
  8, 8,
  0x18, 0x2c, 0x4e, 0x8f, 0xf1, 0x72, 0x34, 0x18,
};

const uint8_t PROGMEM starMask[] = {
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
};

class Medal {
  private:
    Arduboy2 *ab;
    uint8_t x;
    uint8_t y;

  public:
    Medal(Arduboy2 *ab_ptr) 
      : ab(ab_ptr),
        x(setX()),
        y(setY()) {}

    uint8_t setX() {
      return 2;
    }

    uint8_t setY() {
      return 2;
    }

    void draw() {
      ab->drawExternalMask(x, y, star, starMask, frame, 0);
    }
};

#endif