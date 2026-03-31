#ifndef ENEMY_H
#define ENEMY_H 
// 8x8, 1 frame(s)
// Image: 10 bytes, Mask: 8 bytes
// Example: Sprites::drawExternalMask(x, y, image, imageMask, frame, 0);
const uint8_t PROGMEM ghost[] = {
  8, 8,
  0x3c, 0x76, 0xdf, 0xd7, 0xff, 0xfe, 0xfc, 0x60,
};

const uint8_t PROGMEM ghostMask[] = {
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0x60,
};

class Enemy {
  private:
    uint16_t x;
    uint16_t y;

  public:
    Enemy(uint16_t x, uint16_t y)
      : x(x), y(y) {}

    void draw(uint16_t offset_x, uint16_t offset_y) {
      Sprites::drawExternalMask(x - offset_x, y - offset_y, ghost, ghostMask, 0, 0);
    }
};

#endif