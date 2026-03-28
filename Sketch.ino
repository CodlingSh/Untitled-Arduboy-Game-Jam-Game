#include "player.h"
#include <Arduboy2.h>
#include <ArduboyTones.h>

Arduboy2 ab;
ArduboyTones sound(ab.audio.enabled);
Player player(&ab, &sound);

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

}

void draw() {
  player.draw();
}
