#ifndef CLOUDMAP_H
#define CLOUDMAP_H

#include "compass.h"

// 8x8, 1 frame(s)
// Image: 10 bytes, Mask: 8 bytes
// Example: Sprites::drawExternalMask(x, y, cloud, cloudMask, frame, 0);
const uint8_t PROGMEM cloud[] = {
  8, 8,
  0x3c, 0x7e, 0xdf, 0xbf, 0xbf, 0xbe, 0x7c, 0x38,
};

const uint8_t PROGMEM cloudMask[] = {
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xfe, 0x7c, 0x38,
};

// Cloud maps
const uint16_t map1[16] = {
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
  0b0010000000000000,//000100000000000000010000000000000001000000000000,
  0b0111000000000000,//001110000000000000111000000000000011100000000000,
  0b0010000000000000,//000100000000000000010000000000000001000000000000,
  0b0000000110000000,//000000011000000000000001100000000000000110000000,
  0b0000000011000000,//000000001100000000000000110000000000000011000000,
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
  0b0001000000000000,//000100000000000000010000000000000001000000000000,
  0b0011100000000000,//001110000000000000111000000000000011100000000000,
  0b0001000000000000,//000100000000000000010000000000000001000000000000,
  0b0000000110000000,//000000011000000000000001100000000000000110000000,
  0b0000000011000000,//000000001100000000000000110000000000000011000000,
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
  0b0000000000000000,//000000000000000000000000000000000000000000000000,
};

class CloudMap {
  private:
    Compass *compass;
    double xOffset = 0;
    double yOffset = 0;
    float speed = 0.25;
    bool windBlowing = false;
    uint8_t windDirection = 5; // 0 = N, 1 = E, 2 = S, 3 = W, 5 = none
    uint8_t secondTimer = 60;
    uint8_t windTimer = 0;
  public:
    CloudMap(Compass *com_ptr) : compass(com_ptr) {}

    void update() {
      // yOffset -= 0.25;
      if (windBlowing == false) {
        secondTimer--;

        if (secondTimer == 0) {
          windBlowing = true;
          windTimer = 2;//random(2, 5);
          secondTimer = 60;
        }
      }

      if (windBlowing == true && windDirection == 5) {
        windDirection = random(5);
        compass->changeDir(windDirection);
      }        

      switch(windDirection) {
        case 0: // North
          yOffset += speed;
          break;
        case 1: // East
          xOffset -= speed;
          break;
        case 2: // South
          yOffset -= speed;
          break;
        case 3: // West
          xOffset += speed;
      }

      if (windBlowing == true) {
        secondTimer--;

        if (secondTimer == 0) {
          windTimer--;
          secondTimer = 60;
        }

        if (windTimer == 0) {
          windBlowing = false;
          windDirection = 5;
        }
      }
    }

    bool cloudCollide(uint8_t playerX, uint8_t playerY) {
      uint8_t mapPixelX = playerX + (int8_t)xOffset;
      uint8_t mapPixelY = playerY + (int8_t)yOffset;
      
      // Top-left
      uint8_t gridX = mapPixelX / 8;
      uint8_t gridY = mapPixelY / 8;
      if (((map1[gridY] >> (63 - gridX)) & 1ULL)) return true;

      // Top-right
      gridX = (mapPixelX + 7) / 8;
      gridY = mapPixelY / 8;
      if (((map1[gridY] >> (63 - gridX)) & 1ULL)) return true;

      // Bottom-left
      gridX = mapPixelX / 8;
      gridY = (mapPixelY + 7) / 8;
      if (((map1[gridY] >> (63 - gridX)) & 1ULL)) return true;

      // Bottom-right
      gridX = (mapPixelX + 7) / 8;
      gridY = (mapPixelY + 7) / 8;
      if (((map1[gridY] >> (63 - gridX)) & 1ULL)) return true;

      return false;
    }


    void draw() {
      int16_t xOff = (int16_t)xOffset;
      int16_t yOff = (int16_t)yOffset;

      int16_t xStart = xOff >> 3;
      int16_t yStart = yOff >> 3;

      int16_t xEnd = xStart + 9; // 8 visible tiles + 1 partial tile
      int16_t yEnd = yStart + 9;

      for (int8_t y = yStart; y < yEnd; y++) {
        for (int8_t x = xStart; x < xEnd; x++) {
          if ((map1[y] >> (15 - x)) & 1 == 1) {
            Sprites::drawExternalMask(x * 8 - xOffset, y * 8 - yOffset, cloud, cloudMask, 0, 0);
          }
        }
      }
      // Sprites::drawExternalMask(20, 10, cloud, cloudMask, 0, 0);
    }

    uint16_t getMap() {
      return map1;
    }
};

#endif
