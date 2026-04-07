/*
  Untitled Cloud Dodging Game
  Arduboy Game

  Author: Sheldon Codling
  Start Date: 2026-04-05

  Description:
  Top-down game where you avoid getting crushed between edged of the screen and clouds
*/

#include <Arduboy2.h>
#include "compass.h"
#include "player.h"

Arduboy2 ab;
Player player(&ab);
Compass compass(&ab);
uint8_t currentLives;
uint16_t score;

void setup() {
  ab.begin();
  ab.setFrameRate(60);
  currentLives = 3;
  score = 0;
}

void loop() {
  if (!ab.nextFrame()) return;

  ab.pollButtons();
  ab.clear();

  player.update();
  player.draw();
  compass.draw(currentLives, score);

  ab.display();
}
