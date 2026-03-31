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
    uint16_t x = 60;
    uint16_t y = 26;

    uint8_t *currSprite = human;

  public:
    Player(Arduboy2 *abPtr, ArduboyTones *soundPtr)
      : ab(abPtr), sound(soundPtr) {}
    
    uint8_t get_center_x() {
      return x + 4;
    }

    uint8_t get_center_y() {
      return y + 5;
    }

    void update() {
      if (ab->pressed(LEFT_BUTTON)) {
        x--;
      } else if (ab->pressed(RIGHT_BUTTON)) {
        x++;
      }

      if (ab->pressed(UP_BUTTON)) {
        y--;
      } else if (ab->pressed(DOWN_BUTTON)) {
        y++;
      }  
    }

    void draw(uint16_t offset_x, uint16_t offset_y) {
      Sprites::drawSelfMasked(x - offset_x, y - offset_y, currSprite, 0);
      ab->print("X: ");
      ab->println(x);
      ab->print("Y: ");
      ab->println(y);
    }
};

#endif