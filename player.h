#ifndef PLAYER_H
#define PLAYER_H

#include <Arduboy2.h>
#include <ArduboyTones.h>

// 8x16, 1 frame(s)
// Image: 18 bytes, Mask: 16 bytes
// Example: Sprites::drawExternalMask(x, y, player, playerMask, frame, 0);
const uint8_t PROGMEM human[] = {
  8, 11,
  0x80, 0xde, 0xbb, 0xaf, 0xaf, 0xbb, 0xde, 0x80, 0x01, 0x00, 0x07, 0x03,
  0x03, 0x07, 0x00, 0x01,
};

const uint8_t PROGMEM humanMask[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x07, 0x07, 0x07,
  0x07, 0x07, 0x07, 0x07,
};

class Player {
  private:
    Arduboy2 *ab;
    ArduboyTones *sound;
    // ArduboyTones *sound;
    uint8_t x = 30;
    uint8_t y = 30;
    uint8_t *currSprite = human;

  public:
    Player(Arduboy2 *abPtr, ArduboyTones *soundPtr)
      : ab(abPtr), sound(soundPtr) {}

    void update()

    void draw() {
      Sprites::drawSelfMasked(x, y, currSprite, 0);
    }


};

#endif