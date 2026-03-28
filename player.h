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
    uint8_t x = 60;
    uint8_t y = 26;
    int16_t map_scroll_x = 0;
    int16_t map_scroll_y = 0;
    uint8_t *currSprite = human;

  public:
    Player(Arduboy2 *abPtr, ArduboyTones *soundPtr)
      : ab(abPtr), sound(soundPtr) {}
    
    // Getters
    int16_t get_map_scroll_x() {
      return map_scroll_x;
    }

    int16_t get_map_scroll_y() {
      return map_scroll_y;
    }

    void update() {
      if (ab->pressed(LEFT_BUTTON)) {
        map_scroll_x++;
      } else if (ab->pressed(RIGHT_BUTTON)) {
        map_scroll_x--;
      }

      if (ab->pressed(UP_BUTTON)) {
        map_scroll_y++;
      } else if (ab->pressed(DOWN_BUTTON)) {
        map_scroll_y--;
      }  
    }

    void draw() {
      Sprites::drawSelfMasked(x, y, currSprite, 0);
      ab->print("X: ");
      ab->println(map_scroll_x);
      ab->print("Y: ");
      ab->println(map_scroll_y);
    }


};

#endif