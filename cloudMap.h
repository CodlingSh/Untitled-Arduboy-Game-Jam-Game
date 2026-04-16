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
  0b0011100000000000,
  0b0000000000000000,
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
  public:

    void update() {
      yOffset -= 0.25;
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
};

#endif
