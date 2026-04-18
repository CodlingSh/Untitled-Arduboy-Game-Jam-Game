#ifndef SCORE_H;
#define SCORE_H

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, one, 11, 16, WHITE);
const uint8_t PROGMEM one[] = {
  0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x1e, 0xff, 0xff, 0xfe, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x0e,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, two, 11, 16, WHITE);
const uint8_t PROGMEM two[] = {
  0x00, 0x0c, 0x1e, 0x9f, 0xcf, 0xc7, 0xe7, 0x7f, 0x7e, 0x3c, 0x00, 0x00,
  0x0c, 0x1f, 0x1f, 0x1f, 0x0d, 0x0e, 0x1e, 0x1e, 0x1e, 0x0c,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, three, 11, 16, WHITE);
const uint8_t PROGMEM three[] = {
  0x00, 0x0c, 0x1e, 0x1f, 0x0f, 0x67, 0xf7, 0xff, 0xde, 0x8c, 0x00, 0x00,
  0x06, 0x0f, 0x1f, 0x1e, 0x1c, 0x1c, 0x1f, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, four, 11, 16, WHITE);
const uint8_t PROGMEM four[] = {
  0x00, 0x80, 0xe0, 0xf8, 0xbc, 0x9e, 0xff, 0xff, 0xff, 0xe0, 0xe0, 0x00,
  0x03, 0x03, 0x03, 0x03, 0x01, 0x0f, 0x1f, 0x1f, 0x0e, 0x00,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, five, 11, 16, WHITE);
const uint8_t PROGMEM five[] = {
  0x00, 0x0e, 0x7e, 0x7e, 0x7e, 0x6f, 0xef, 0xef, 0xcf, 0xcf, 0x00, 0x00,
  0x06, 0x0f, 0x0f, 0x1e, 0x1e, 0x1e, 0x1f, 0x0f, 0x0f, 0x07,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, six, 11, 16, WHITE);
const uint8_t PROGMEM six[] = {
  0x00, 0xe0, 0xf8, 0xfc, 0x7e, 0x3f, 0x6f, 0xe7, 0xe7, 0xc0, 0x80, 0x00,
  0x07, 0x0f, 0x1f, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x0f, 0x07,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, seven, 11, 16, WHITE);
const uint8_t PROGMEM seven[] = {
  0x00, 0x1e, 0x1e, 0x1e, 0xce, 0xef, 0xff, 0x3f, 0x0f, 0x07, 0x03, 0x00,
  0x00, 0x00, 0x0f, 0x1f, 0x1f, 0x1f, 0x0e, 0x00, 0x00, 0x00,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, eight, 11, 16, WHITE);
const uint8_t PROGMEM eight[] = {
  0x00, 0x1c, 0xbe, 0xff, 0xef, 0x67, 0xf7, 0xff, 0xde, 0x8c, 0x00, 0x00,
  0x07, 0x0f, 0x1f, 0x1c, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, nine, 11, 16, WHITE);
const uint8_t PROGMEM nine[] = {
  0x00, 0x3c, 0x7e, 0xfe, 0xff, 0xcf, 0xc7, 0x67, 0xff, 0xfe, 0xfc, 0x00,
  0x00, 0x00, 0x0c, 0x1e, 0x1e, 0x1e, 0x1e, 0x0f, 0x07, 0x03,
};

// 11x16, 1 frame(s), 22 bytes
// Example: Arduboy2Base::drawBitmap(x, y, nine, 11, 16, WHITE);
const uint8_t PROGMEM zero[] = {
  0x00, 0xc0, 0xf8, 0xfe, 0x3f, 0x0f, 0x0f, 0x1f, 0xff, 0xfe, 0xfc, 0x00,
  0x07, 0x0f, 0x1f, 0x1e, 0x1c, 0x1e, 0x1f, 0x0f, 0x07, 0x01,
};

// 12x16, 1 frame(s), 24 bytes
// Example: Arduboy2Base::drawBitmap(x, y, bigMedal, 12, 16, WHITE);
const uint8_t PROGMEM bigMedal[] = {
  0x60, 0x90, 0x48, 0xc4, 0xc2, 0xc1, 0x3d, 0x3a, 0x34, 0x28, 0x90, 0x60,
  0x00, 0x00, 0x01, 0x02, 0x05, 0x0b, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00,
};

class Score {
  private:
    int16_t score = 0;
    uint8_t onesScore = 0;
    uint8_t tensScore = 0;
    uint8_t hundredsScore = 0;
    uint8_t thousandsScore = 0;
    boolean tensVis = false;
    boolean hundredsVis = false;
    boolean thousandsVis = false;
  
  public:
    void resetScore() {
      score = 0;
      onesScore = 0;
      tensScore = 0;
      hundredsScore = 0;
      thousandsScore = 0;
    }

    void incScore(int8_t points) {
      score += points;

      if (onesScore > 9) {
        onesScore = 0;
        tensVis = true;
        tensScore++;
      }

      if (tensScore > 9) {
        tensScore = 0;
        hundredsVis = true;
        hundredsScore++;
      }

      if (hundredsScore > 9) {
        hundredsScore = 0;
        thousandsVis = true;
        thousandsScore++;
      }
      
    }

    void draw() {
      uint8_t *onesSpr = zero, *tensSpr = zero, *hundredsSpr = zero, *thousandsSpr = zero;
      uint8_t onesX = 78, tensX = 78, hundredsX = 78, thousandsX = 78;

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

      // Draw medal icon
      Arduboy2Base::drawBitmap(65, 49, bigMedal, 12, 16, WHITE);

      // Draw score for ones
      switch(onesScore) {
        case 0:
          onesSpr = zero;
          break;
        case 1:
          onesSpr = one;
          break;
        case 2:
          onesSpr = two;
          break;
        case 3:
          onesSpr = three;
          break;
        case 4:
          onesSpr = four;
          break;
        case 5:
          onesSpr = five;
          break;
        case 6:
          onesSpr = six;
          break;
        case 7:
          onesSpr = seven;
          break;
        case 8:
          onesSpr = eight;
          break;
        case 9:
          onesSpr = nine;
          break;
      }

      // Draw score for tens
      switch(tensScore) {
        case 0:
          tensSpr = zero;
          break;
        case 1:
          tensSpr = one;
          break;
        case 2:
          tensSpr = two;
          break;
        case 3:
          tensSpr = three;
          break;
        case 4:
          tensSpr = four;
          break;
        case 5:
          tensSpr = five;
          break;
        case 6:
          tensSpr = six;
          break;
        case 7:
          tensSpr = seven;
          break;
        case 8:
          tensSpr = eight;
          break;
        case 9:
          tensSpr = nine;
          break;
      }

      // Draw score for hundreds
      switch(hundredsScore) {
        case 0:
          hundredsSpr = zero;
          break;
        case 1:
          hundredsSpr = one;
          break;
        case 2:
          hundredsSpr = two;
          break;
        case 3:
          hundredsSpr = three;
          break;
        case 4:
          hundredsSpr = four;
          break;
        case 5:
          hundredsSpr = five;
          break;
        case 6:
          hundredsSpr = six;
          break;
        case 7:
          hundredsSpr = seven;
          break;
        case 8:
          hundredsSpr = eight;
          break;
        case 9:
          hundredsSpr = nine;
          break;
      }

      // Draw score for ones
      switch(thousandsScore) {
        case 0:
          thousandsSpr = zero;
          break;
        case 1:
          thousandsSpr = one;
          break;
        case 2:
          thousandsSpr = two;
          break;
        case 3:
          thousandsSpr = three;
          break;
        case 4:
          thousandsSpr = four;
          break;
        case 5:
          thousandsSpr = five;
          break;
        case 6:
          thousandsSpr = six;
          break;
        case 7:
          thousandsSpr = seven;
          break;
        case 8:
          thousandsSpr = eight;
          break;
        case 9:
          thousandsSpr = nine;
          break;
      }

      // Draw score
      Arduboy2Base::drawBitmap(onesX, 49, onesSpr, 11, 16, WHITE);
      if (tensVis) {Arduboy2Base::drawBitmap(tensX, 49, tensSpr, 11, 16, WHITE);}
      if (hundredsVis) {Arduboy2Base::drawBitmap(hundredsX, 49, hundredsSpr, 11, 16, WHITE);}
      if (thousandsVis) {Arduboy2Base::drawBitmap(thousandsX, 49, thousandsSpr, 11, 16, WHITE);}
    }

    int16_t getScore() {
      return score;
    }
};

#endif