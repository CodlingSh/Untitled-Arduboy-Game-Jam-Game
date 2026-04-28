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
// Move clouds with a nice linear acceleration and decelleration
// Rotate arrow and change wind direction
// Cause life to be lost when crushed against wall by cloud
// Make nice title screen
// add instructions
// add music and sound effects
// Adjust score values to closer match 1 - 50 and not 1 - 42

#include <Arduboy2.h>
#include "compass.h"
#include "player.h"
#include "medal.h"
#include "score.h"
#include "cloudMap.h"
#include "title.h"

Arduboy2 ab;
Compass compass(&ab);
Medal medal(&ab);
CloudMap clouds(&compass);
Player player(&ab, &clouds);
uint8_t currentLives;
Score score;
Title title(&ab);
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
      // ab.setCursor(32, 32);
      // ab.println("TITLE SCREEN");
      title.update();
      title.draw();

      if (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON)) {
        gameState = title.getSelection() + 1; // Adding 1 to make up for 0 index of selection
        
        if (gameState == 1) {
          ab.initRandomSeed();
          medal.spawn(player.getX(), player.getY());
        }
      }
      break;
    case 1:
      clouds.update();
      player.update();
      player.draw();
      clouds.draw();
      ab.fillRect(64, 1, 8, 63, BLACK);
      score.draw();
      compass.draw(currentLives);
      medal.update();
      medal.draw();
      if (collides(player, medal)) {
        score.incScore(medal.getTimerScore());
        medal.spawn(player.getX(), player.getY());
      }
      if (clouds.cloudCollide(player.getX(), player.getY())) {
        ab.print("T");

      }
      ab.setCursor(111, 57);
      ab.println(ab.cpuLoad());
      ab.setCursor(1, 47);
      ab.println(clouds.getXOffset());
      ab.println(clouds.getYOffset());
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
