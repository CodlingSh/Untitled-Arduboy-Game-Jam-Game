#ifndef CLOUDMAP_H
#define CLOUDMAP_H

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
  0b0000000000000000,
  0b0001000000000000,
  0b0011100000000000,
  0b0001000000000000,
  // 0b1110101010101111,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101,
  // 0b1010101010101010,
  // 0b0101010101010101
};

class CloudMap {
  private:
    float xOffset = 0;
    float yOffset = 0;
    float speed = 0.25;
    bool windBlowing = false;
    uint8_t windDirection = 5; // 0 = N, 1 = E, 2 = S, 3 = W, 5 = none
    uint8_t secondTimer = 60;
    uint8_t windTimer = 0;
  public:

    void update() {
      // yOffset -= 0.25;
      if (windBlowing == false) {
        secondTimer--;

        if (secondTimer == 0) {
          windBlowing = true;
          secondTimer = 60;
        }
      }

      if (windBlowing == true && windDirection == 5) {
        windDirection = random(4);
      }
        

      switch(windDirection) {
        case 0: // North
          yOffset += speed;
          break;
        case 1: // East
          xOffset += speed;
          break;
        case 2: // South
          yOffset -= speed;
          break;
        case 3: // West
          xOffset -= speed;
      }
    }

    void draw() {
      for (int8_t y = 0; y < 16; y++) {
        for (int8_t x = 0; x < 16; x++) {
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
