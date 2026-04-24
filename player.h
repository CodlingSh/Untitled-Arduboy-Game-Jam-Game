#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include "cloudMap.h"

// 8x8, 1 frame(s), 8 bytes
// Example: Arduboy2Base::drawBitmap(x, y, face, 8, 8, WHITE);
const uint8_t PROGMEM face[] = {
  0x7e, 0xff, 0xd3, 0xbf, 0xbf, 0xd3, 0xff, 0x7e,
};

// 8x8, 1 frame(s)
// Image: 10 bytes, Mask: 8 bytes
// Example: Sprites::drawExternalMask(x, y, hero, heroMask, frame, 0);
const uint8_t PROGMEM heroRight[] = {
  8, 8,
  0x20, 0x10, 0xff, 0xb5, 0x37, 0xfd, 0x90, 0x20,
};

const uint8_t PROGMEM heroMaskRight[] = {
  0x20, 0x10, 0xff, 0xbf, 0x3f, 0xff, 0x90, 0x20,
};

// 8x8, 1 frame(s)
// Image: 10 bytes, Mask: 8 bytes
// Example: Sprites::drawExternalMask(x, y, player, playerMask, frame, 0);
const uint8_t PROGMEM heroLeft[] = {
  8, 8,
  0x20, 0x90, 0xfd, 0x37, 0xb5, 0xff, 0x10, 0x20,
};

const uint8_t PROGMEM heroMaskLeft[] = {
  0x20, 0x90, 0xff, 0x3f, 0xbf, 0xff, 0x10, 0x20,
};

class Player {
  private:
    Arduboy2 *ab;
    CloudMap *clouds;
    int8_t x = 30;
    int8_t y = 30;
    uint8_t height = 8;
    uint8_t width = 8;
    uint8_t xMin = 1;
    uint8_t xMax = 55;
    uint8_t yMin = 1;
    uint8_t yMax = 55;
    boolean lastDirLeft = true;
    uint8_t *currSpr = heroRight;
    uint8_t *currMask = heroMaskRight;
    
  public:
    Player(Arduboy2 *ab_ptr, CloudMap *cloud_ptr) : ab(ab_ptr), clouds(cloud_ptr) {}

    void update() {
      move();

      if (ab->pressed(LEFT_BUTTON)) {
        lastDirLeft = true;
      } else if (ab->pressed(RIGHT_BUTTON)) {
        lastDirLeft = false;
      }

      
      if (clouds->cloudCollide(x - 1, y)) {
        x++;
      }
      
      if (clouds->cloudCollide(x + 1, y)) {
        x--;
      }
      
      if (clouds->cloudCollide(x, y - 1)) {
        y++;
      }
      
      if (clouds->cloudCollide(x, y + 1)) {
        y--;
      }
    }

    void draw() {
      if (lastDirLeft) {
        currSpr = heroLeft;
        currMask = heroMaskLeft;
      } else {
        currSpr = heroRight;
        currMask = heroMaskRight;
      }
      Sprites::drawExternalMask(x, y, currSpr, currMask, 0, 0);
    }

    int8_t getX() {
      return x;
    }

    int8_t getY() {
      return y;
    }

    void setX(uint8_t newX) {
      x = newX;
    }

    void setY(uint8_t newY) {
      y = newY;
    } 
    
    int8_t getWidth() {
      return width;
    }

    int8_t getHeight() {
      return height;
    }

    void move() {
      if (ab->pressed(LEFT_BUTTON)) {
        if (!clouds->cloudCollide(x - 1, y)) {
          x--;
        }
      }
      if (ab->pressed(RIGHT_BUTTON)) {
        if (!clouds->cloudCollide(x + 1, y)) {
          x++;
        }
      }
      if (ab->pressed(UP_BUTTON)) {
        if (!clouds->cloudCollide(x, y - 1)) {
          y--;
        }
      }
      if (ab->pressed(DOWN_BUTTON)) {
        if (!clouds->cloudCollide(x, y + 1)) {
          y++;
        }
      }

      // if (x < xMin) {
      //   x = xMin;
      // } else if (x > xMax) {
      //   x = xMax;
      // }

      // if (y < yMin) {
      //   y = yMin;
      // } else if (y > yMax) {
      //   y = yMax;
      // }
    }
};

#endif