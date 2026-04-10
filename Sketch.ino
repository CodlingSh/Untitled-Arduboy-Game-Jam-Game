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
#include "medal.h"
#include "score.h"

Arduboy2 ab;
Player player(&ab);
Compass compass(&ab);
Medal medal(&ab);
uint8_t currentLives;
uint16_t score;
uint8_t gameState;

void setup() {
  ab.begin();
  ab.initRandomSeed();
  ab.setFrameRate(60);
  currentLives = 3;
  score = 0;
  gameState = 0;
}

void loop() {
  if (!ab.nextFrame()) return;

  ab.pollButtons();
  ab.clear();

  switch (gameState) {
    case 0:
      ab.setCursor(32, 32);
      ab.println("TITLE SCREEN");

      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        medal.spawn();
        gameState = 1;
      }
      break;
    case 1:
      player.update();
      player.draw();
      compass.draw(currentLives, score);
      medal.draw();
      break;
  }

  

  ab.display();
}
