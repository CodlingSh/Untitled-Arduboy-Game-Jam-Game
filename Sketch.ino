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
#include "cloudMap.h"

Arduboy2 ab;
Player player(&ab);
Compass compass(&ab);
Medal medal(&ab);
CloudMap clouds;
uint8_t currentLives;
Score score;
uint8_t gameState;

void setup() {
  ab.begin();
  ab.setFrameRate(60);
  currentLives = 3;
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
        ab.initRandomSeed();
        medal.spawn(player.getX(), player.getY());
        gameState = 1;
      }
      break;
    case 1:
      player.update();
      player.draw();
      clouds.update();
      clouds.draw();
      compass.draw(currentLives);
      score.draw();
      medal.update();
      medal.draw();
      if (collides(player, medal)) {
        score.incScore(medal.getTimerScore());
        medal.spawn(player.getX(), player.getY());
      }
      // ab.println(collides(player, medal));
      break;
  }

  ab.display();
}

template<typename A, typename B>
bool collides(const A& a, const B& b) {
  if 
    (a.getX() + a.getWidth() > b.getX() &&
    a.getX() < b.getX() + b.getWidth() &&
    a.getY() + a.getHeight() > b.getY() &&
    a.getY() < b.getY() + b.getHeight())
    {
      return true;
    }
  
  return false;
}
