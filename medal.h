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
    uint8_t x = 0;
    uint8_t y = 0;

  public:
    Medal(Arduboy2 *ab_ptr) 
      : ab(ab_ptr) {}

    uint8_t setX() {
      uint8_t rnd = random(8) * 8 + 64;
      return rnd;
    }

    uint8_t setY() {
      uint8_t rnd = random(8) * 8;
      return rnd;
    }

    void spawn(uint8_t playerX, uint8_t playerY) {
      uint8_t rndX;
      uint8_t rndY;

      rndX = random(8) * 8;
      rndY = random(8) * 8;

      while ((rndX - (playerX + 4) * -1) <= 16) {
        rndX = random(8) * 8 + 64;
      }

      while ((rndY - (playerY + 4) * -1) <= 16) {
        rndY = random(8) * 8;
      }

      x = rndX;
      y = rndY;
    }

    void draw() {
      Sprites::drawExternalMask(x, y, star, starMask, 0, 0);
      // ab->print("X: ");
      // ab->println(x);
      // ab->print("Y: ");
      // ab->println(y);
    }
};

#endif