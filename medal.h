#ifndef MEDAL_H
#define MEDAL_H

#include <Arduboy2.h>

// 8x8, 8 frame(s)
// Image: 66 bytes, Mask: 64 bytes
// Example: Sprites::drawExternalMask(x, y, medal, medalMask, frame, 0);
const uint8_t PROGMEM star[] = {
  8, 8,
  // Frame 0
  0x18, 0x2c, 0x4e, 0x8f, 0xf1, 0x72, 0x34, 0x18,
  // Frame 1
  0x18, 0x3c, 0x5e, 0x89, 0x91, 0x7a, 0x3c, 0x18,
  // Frame 2
  0x18, 0x3c, 0x7e, 0x91, 0x89, 0x7e, 0x3c, 0x18,
  // Frame 3
  0x18, 0x3c, 0x7a, 0x91, 0x89, 0x5e, 0x3c, 0x18,
  // Frame 4
  0x18, 0x34, 0x72, 0xf1, 0x8f, 0x4e, 0x2c, 0x18,
  // Frame 5
  0x18, 0x24, 0x62, 0xf7, 0xef, 0x46, 0x24, 0x18,
  // Frame 6
  0x18, 0x24, 0x66, 0xef, 0xf7, 0x66, 0x24, 0x18,
  // Frame 7
  0x18, 0x24, 0x46, 0xef, 0xf7, 0x62, 0x24, 0x18,
};

const uint8_t PROGMEM starMask[] = {
  // Frame 0
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 1
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 2
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 3
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 4
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 5
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 6
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
  // Frame 7
  0x18, 0x3c, 0x7e, 0xff, 0xff, 0x7e, 0x3c, 0x18,
};

class Medal {
  private:
    Arduboy2 *ab;
    uint8_t x = 0;
    uint8_t y = 0;
    uint8_t height = 8;
    uint8_t width = 8;
    uint8_t timer = 42;
    uint8_t localT = 60;
    uint8_t animTimer = 3;
    uint8_t currFrame = 1;

  public:
    Medal(Arduboy2 *ab_ptr) : ab(ab_ptr) {}

    uint8_t setX() {
      uint8_t rnd = random(8) * 8 + 64;
      return rnd;
    }

    uint8_t setY() {
      uint8_t rnd = random(8) * 8;
      return rnd;
    }

    uint8_t getX() {
      return x;
    }

    uint8_t getY() {
      return y;
    }

    uint8_t getWidth() {
      return width;
    }

    uint8_t getHeight() {
      return height;
    }

    void spawn(uint8_t playerX, uint8_t playerY) {
      uint8_t rndX;
      uint8_t rndY;

      rndX = random(52) + 2;
      rndY = random(52) + 2;

      while (abs(rndX - (playerX + 4)) <= 20) {
        rndX = random(52) + 2;
      }

      while ((abs(rndY - (playerY + 4)) <= 20)) {
        rndY = random(52) + 2;
      }

      x = rndX;
      y = rndY;
      timer = 42;
      localT = 60;
    }

    uint8_t getTimerScore() {
      return timer + 1;
    }

    void animate() {
      animTimer--;

      if (animTimer == 0) {
        currFrame++;

        if (currFrame > 7) {
          currFrame = 0;
        }

        animTimer = 3;
      }
    }

    void update() {
      // Decrease timer
      if (timer != 0) {localT--;}
      
      if (localT == 0) {
        if (timer != 0) {
          timer--;
          localT = 3;
        }
      }

      animate();
    }

    void draw() {
      Sprites::drawExternalMask(x, y, star, starMask, currFrame, 0);
      // ab->print("X: ");
      // ab->println(x);
      // ab->println(localT);
      // ab->println(timer);
      
      // Draw timer bar
      ab->fillRect(65, 44 - timer, 4, 0 + timer);
    }
};

#endif