#ifndef SCORE_H;
#define SCORE_H

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, one, 11, 16, WHITE);
const uint8_t PROGMEM one[] = {
  11, 13,
  0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x1e, 0xff, 0xff, 0xfe, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x0e,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, two, 11, 16, WHITE);
const uint8_t PROGMEM two[] = {
  11, 13,
  0x00, 0x0c, 0x1e, 0x9f, 0xcf, 0xc7, 0xe7, 0x7f, 0x7e, 0x3c, 0x00, 0x00,
  0x0c, 0x1f, 0x1f, 0x1f, 0x0d, 0x0e, 0x1e, 0x1e, 0x1e, 0x0c,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, three, 11, 16, WHITE);
const uint8_t PROGMEM three[] = {
  11, 13,
  0x00, 0x0c, 0x1e, 0x1f, 0x0f, 0x67, 0xf7, 0xff, 0xde, 0x8c, 0x00, 0x00,
  0x06, 0x0f, 0x1f, 0x1e, 0x1c, 0x1c, 0x1f, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, four, 11, 16, WHITE);
const uint8_t PROGMEM four[] = {
  11, 13,
  0x00, 0x80, 0xe0, 0xf8, 0xbc, 0x9e, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x00,
  0x03, 0x03, 0x03, 0x03, 0x01, 0x0f, 0x1f, 0x1f, 0x0e, 0x00,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, five, 11, 16, WHITE);
const uint8_t PROGMEM five[] = {
  11, 13,
  0x00, 0x0e, 0x7e, 0x7e, 0x7e, 0x6f, 0xef, 0xef, 0xcf, 0xcf, 0x00, 0x00,
  0x06, 0x0f, 0x0f, 0x1e, 0x1e, 0x1e, 0x1f, 0x0f, 0x0f, 0x07,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, six, 11, 16, WHITE);
const uint8_t PROGMEM six[] = {
  11, 13,
  0x00, 0xe0, 0xf8, 0xfc, 0x7e, 0x3f, 0x6f, 0xe7, 0xe7, 0xc0, 0x80, 0x00,
  0x07, 0x0f, 0x1f, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x0f, 0x07,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, seven, 11, 16, WHITE);
const uint8_t PROGMEM seven[] = {
  11, 13,
  0x00, 0x1e, 0x1e, 0x1e, 0xce, 0xef, 0xff, 0x3f, 0x0f, 0x07, 0x03, 0x00,
  0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00, 0x00, 0x00,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, eight, 11, 16, WHITE);
const uint8_t PROGMEM eight[] = {
  11, 13,
  0x00, 0x1c, 0xbe, 0xff, 0xef, 0x67, 0xf7, 0xff, 0xde, 0x8c, 0x00, 0x00,
  0x07, 0x0f, 0x1f, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, nine, 11, 16, WHITE);
const uint8_t PROGMEM nine[] = {
  11, 13,
  0x00, 0x3c, 0x7e, 0xfe, 0xff, 0xcf, 0xc7, 0x67, 0xff, 0xfe, 0xfc, 0x00,
  0x00, 0x00, 0x0c, 0x1e, 0x1e, 0x1e, 0x1e, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, nine, 11, 16, WHITE);
const uint8_t PROGMEM zero[] = {
  11, 13,
  0x00, 0xc0, 0xf8, 0xfe, 0x3f, 0x0f, 0x0f, 0x1f, 0xff, 0xfe, 0xfc, 0x00,
  0x07, 0x0f, 0x1f, 0x1e, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x01,
};

class Score {
  private:
    uint32_t score = 0;
    uint8_t onesScore = 0;
    uint8_t tensScore = 0;
    uint8_t hundredsScore = 0;
    uint8_t thousandsScore = 0;
    uint8_t tenthousandsScore = 0;
    boolean tensVis = false;
    boolean hundredsVis = false;
    boolean thousandsVis = false;
    boolean tenthousandsVis = false;
  
  public:
    void resetScore() {
      score = 0;
      onesScore = 0;
      tensScore = 0;
      hundredsScore = 0;
      thousandsScore = 0;
      tensVis = false;
      hundredsVis = false;
      thousandsVis = false;
      tenthousandsVis = false;
    }

    void incScore(int8_t points) {
      score += points;

      tenthousandsScore = score / 10000;
      thousandsScore = (score / 1000) % 10;
      hundredsScore = (score / 100) % 10;
      tensScore = (score / 10) % 10;
      onesScore = (score / 1) % 10;
    }

    const uint8_t* getSprite(uint8_t number) {
      switch(number) {
        case 0:
          return zero;
          break;
        case 1:
          return one;
          break;
        case 2:
          return two;
          break;
        case 3:
          return three;
          break;
        case 4:
          return four;
          break;
        case 5:
          return five;
          break;
        case 6:
          return six;
          break;
        case 7:
          return seven;
          break;
        case 8:
          return eight;
          break;
        case 9:
          return nine;
          break;
      }
    }

    void draw(int8_t xOffset, int8_t yOffset) {
       uint8_t onesX = 66, tensX = 66, hundredsX = 66, thousandsX = 66, tenthousandsX = 66;

      if (tenthousandsVis) {
        onesX += 12;
        tensX += 12;
        hundredsX += 12;
        thousandsX += 12;
      }
      if (thousandsVis) {
        onesX += 12;
        tensX += 12;
        hundredsX += 12;
      }
      if (hundredsVis) {
        onesX += 12;
        tensX += 12;
      }
      if (tensVis) {
        onesX += 12;
      }

      // Check what digits to display
      if (score > 9) {
        tensVis = true;
      } 
      if (score > 99) {
        hundredsVis = true;
      }
      if (score > 999) {
        thousandsVis = true;
      }
      if (score > 9999) {
        tenthousandsVis = true;
      }

// Sprites::drawOverwrite(72, 0, arrowUp, 0);
      Sprites::drawOverwrite(onesX + xOffset, 48 + yOffset, getSprite(onesScore), 0);
      if (tensVis) {Sprites::drawOverwrite(tensX + xOffset, 48 + yOffset, getSprite(tensScore), 0);}
      if (hundredsVis) {Sprites::drawOverwrite(hundredsX + xOffset, 48 + yOffset, getSprite(hundredsScore), 0);}
      if (thousandsVis) {Sprites::drawOverwrite(thousandsX + xOffset, 48 + yOffset, getSprite(thousandsScore), 0);}
      if (tenthousandsVis) {Sprites::drawOverwrite(tenthousandsX + xOffset, 48 + yOffset, getSprite(tenthousandsScore), 0);}
    }

    int32_t getScore() {
      return score;
    }
};

#endif