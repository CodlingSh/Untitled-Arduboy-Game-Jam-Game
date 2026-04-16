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
    int8_t x = 30;
    int8_t y = 30;
    int8_t height = 8;
    int8_t width = 8;
    int8_t xMin = 0;
    int8_t xMax = 56;
    int8_t yMin = 0;
    int8_t yMax = 56;
  public:
    Player(Arduboy2 *ab_ptr) : ab(ab_ptr) {}

    void update() {
      move();
    }

    int8_t getX() {
      return x;
    }

    int8_t getY() {
      return y;
    }
    
    int8_t getWidth() {
      return width;
    }

    int8_t getHeight() {
      return height;
    }

    void draw() {
      ab->drawBitmap(x, y, face, 8, 8, WHITE);
    }

    void move() {
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

      if (x < xMin) {
        x = xMin;
      } else if (x > xMax) {
        x = xMax;
      }

      if (y < yMin) {
        y = yMin;
      } else if (y > yMax) {
        y = yMax;
      }
    }
};

#endif