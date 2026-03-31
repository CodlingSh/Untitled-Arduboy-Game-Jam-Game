#include "player.h"
#include "level.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>
#include "enemy.h"
#include "camera.h"

Arduboy2 ab;
ArduboyTones sound(ab.audio.enabled);
Camera c(0, 0);
Player player(&ab, &sound);
Enemy enemy(60, 60);
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
  c.update(player.get_center_x(), player.get_center_y());
}

void draw() {
  player.draw(c.scroll_x(), c.scroll_y());
  level.draw(c.scroll_x(), c.scroll_y());
  enemy.draw(c.scroll_x(), c.scroll_y());
}
