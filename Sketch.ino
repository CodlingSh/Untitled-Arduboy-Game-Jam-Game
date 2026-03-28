#include "player.h"
#include "level.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 ab;
ArduboyTones sound(ab.audio.enabled);
Player player(&ab, &sound);
Level level(&ab, 0b11111111);

void setup() {
  ab.begin();
  ab.setFrameRate(60);
}

void loop() {
  if (!ab.nextFrame()) return;

  ab.pollButtons();
  ab.clear();

  update();
  draw();

  ab.display();
}

void update() {
  player.update();
}

void draw() {
  player.draw();
  level.draw(player.get_map_scroll_x(), player.get_map_scroll_y());
}
