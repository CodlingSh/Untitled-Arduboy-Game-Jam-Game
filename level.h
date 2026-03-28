#ifndef LEVEL_H
#define LEVEL_H

#include <Arduboy2.h>


class Level {
  private:
    Arduboy2 *ab;
    uint8_t map_data; // bit 7 = width is x2, bit 6 = height is x2, rest gives level number
    uint8_t map[];

  public:
    Level(Arduboy2 *ab_ptr, uint8_t map_data) : ab(ab_ptr), map_data(map_data) {}

    uint8_t get_map_data() {
      return map_data;
    }

  void draw(uint16_t map_scroll_x, uint16_t map_scroll_y) {
    uint8_t width;
    uint8_t height;

    if (get_map_data() & (1 << 7)) {
      width = 254;
    } else {
      width = 127;
    }

    if (get_map_data() & (1 << 6)) {
      height = 127;
    } else {
      height = 63;
    }

    ab->fillRect(0 + map_scroll_x, 0 + map_scroll_y, width, 1);
    ab->fillRect(0 + map_scroll_x, height + map_scroll_y, width, 1);
    ab->fillRect(0 + map_scroll_x, 0 + map_scroll_y, 1, height);
    ab->fillRect(width + map_scroll_x, 0 + map_scroll_y, 1, height);
  }
};

#endif