/*
  Untitled Cloud Dodging Game
  Arduboy Game

  Author: Sheldon Codling
  Start Date: 2026-04-05

  Description:
  Top-down game where you avoid getting crushed between edged of the screen and clouds
*/

// TODO
// Animate player sprite
// add music and sound effects
// Adjust score values to closer match 1 - 50 and not 1 - 42

#include <Arduboy2.h>
#include "compass.h"
#include "player.h"
#include "medal.h"
#include "score.h"
#include "cloudMap.h"
#include "title.h"
#include "help.h"
#include "credits.h"

Arduboy2 ab;
Compass compass(&ab);
Medal medal(&ab);
CloudMap clouds(&compass);
Player player(&ab, &clouds);
int8_t currentLives;
Score score;
Title title(&ab);
Help helpMe;
Credits theCredits;
uint8_t deathTimer = 360;
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
      title.update();
      title.draw();

      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = title.getSelection() + 1; // Adding 1 to make up for 0 index of selection
        
        if (gameState == 1) {
          resetGame();
        }
      }
      break;
    case 1:
      // Death check
      if (!player.getIsDead()) {
        clouds.update();
        player.update();
        medal.update();

        if (collides(player, medal)) {
          score.incScore(medal.getTimerScore());
          medal.spawn(player.getX(), player.getY());
        }
      } else if (player.getIsDead() && currentLives > 1) {
        deathTimer--;
        if (deathTimer == 0) {
          currentLives--;
          resetLife();
        }
      } else {
        deathTimer--;
        if (deathTimer == 0) {
          gameState = 5;
        }
      }

      player.draw();
      clouds.draw();
      ab.fillRect(64, 1, 8, 63, BLACK);
      score.draw();
      compass.draw(currentLives, clouds.isWindActive());
      medal.draw();
      
      ab.setCursor(111, 57);
      ab.println(ab.cpuLoad());
      ab.setCursor(0, 47);
      ab.println((uint16_t)clouds.getXOffset());
      ab.println((uint16_t)clouds.getYOffset());
      break;
    case 2:
      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = 0;
      }
      helpMe.draw();
      break;
    case 3:
      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = 0;
      }
      ab.println("FUTURE SETTINGS MENU");
      break;
    case 4:
      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = 0;
      }
      theCredits.draw();
      break;
    case 5:
      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = 0;
      }
      ab.println("GAME OVER");
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

void resetGame() {
  resetLife();
  currentLives = 3;
}

void resetLife() {
  ab.initRandomSeed();
  medal.spawn(player.getX(), player.getY());
  player.spawn();
  deathTimer = 360;
}
