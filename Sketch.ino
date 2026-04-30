/*
  Untitled Cloud Dodging Game
  Arduboy Game

  Author: Sheldon Codling
  Start Date: 2026-04-05

  Description:
  Top-down game where you avoid getting crushed between edged of the screen and clouds
*/

// TODO
// add LED for showing value of medals
// Adjust level layout
// Maybe add high score functionality

#include <Arduboy2.h>
#include "compass.h"
#include "player.h"
#include "medal.h"
#include "score.h"
#include "cloudMap.h"
#include "title.h"
#include "help.h"
#include "credits.h"
#include "gameOver.h"
#include <ArduboyTones.h>
#include "settings.h"

const uint16_t pickupJingle[] PROGMEM = {
  NOTE_C6, 50,
  NOTE_E6, 50,
  NOTE_G6, 50,
  NOTE_C7, 80,
  TONES_END
};

const uint16_t deathJingle[] PROGMEM = {
  NOTE_F5, 30,
  NOTE_G5, 50,
  NOTE_F5, 50,
  NOTE_E5, 60,
  NOTE_D5, 60,
  NOTE_C5, 80,
  NOTE_A4, 120,
  TONES_END
};

const uint16_t gameOverJingle[] PROGMEM = {
  NOTE_E5, 120,
  NOTE_C5, 120,
  NOTE_A4, 140,
  NOTE_F4, 160,
  NOTE_D4, 160,
  NOTE_C4, 180,
  NOTE_E4, 140,
  NOTE_G4, 160,
  NOTE_C5, 300,
  TONES_END
};

Arduboy2 ab;
Compass compass(&ab);
Medal medal(&ab);
CloudMap clouds(&compass);
Player player(&ab, &clouds);
int8_t currentLives;
Score score;
Title title(&ab);
Help helpMe;
GameOver gameOver;
Credits theCredits;
Settings setting;
uint8_t deathTimer = 360;
uint8_t gameState;
ArduboyTones sound(ab.audio.enabled);
bool deathSoundPlayed = false;
bool gameOverSoundPlayed = false;
bool ledOn = true;
bool soundOn = true;
int8_t menuSelection = 0;

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
      if (player.getIsDead() && !deathSoundPlayed) {
        if (soundOn) {
          sound.tones(deathJingle);
        }

        deathSoundPlayed = true;
      }

      if (!player.getIsDead()) {
        clouds.update();
        player.update();
        medal.update();

        if (collides(player, medal)) {
          if (soundOn) {
            sound.tones(pickupJingle);
          }
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
      score.draw(0, 0);
      compass.draw(currentLives, clouds.isWindActive());
      medal.draw();
      
      ab.setCursor(111, 57);
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
      if (ab.justPressed(DOWN_BUTTON)) {
        menuSelection++;
      } else if (ab.justPressed(UP_BUTTON)) {
        menuSelection--;
      }

      if (menuSelection < 0) {
        menuSelection = 2;
      } else if (menuSelection > 2) {
        menuSelection = 0;
      }

      if (menuSelection == 0 && (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON) || ab.justPressed(LEFT_BUTTON) || ab.justPressed(RIGHT_BUTTON))) {
        soundOn = !soundOn;
      } else if (menuSelection == 1 && (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON) || ab.justPressed(LEFT_BUTTON) || ab.justPressed(RIGHT_BUTTON))) {
        ledOn = !ledOn;
      } else if (menuSelection == 2 && (ab.justPressed(A_BUTTON) || ab.justPressed(B_BUTTON))) {
        menuSelection = 0;
        gameState = 0;
      }

      setting.draw(menuSelection);

      
      
      if (soundOn) {
        ab.fillRect(65, 17, 24, 2); // LED row
      } else {
        ab.fillRect(94, 17, 31, 2); // LED row
      }
      if (ledOn) {
        ab.fillRect(65, 39, 24, 2); // LED row
      } else {
        ab.fillRect(94, 39, 31, 2); // LED row
      }
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
      if (!gameOverSoundPlayed && soundOn) {
        sound.tones(gameOverJingle);
        gameOverSoundPlayed = true;
      }
      gameOver.draw();
      score.draw(3, -8);
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
  score.resetScore();
  gameOverSoundPlayed = false;
}

void resetLife() {
  ab.initRandomSeed();
  medal.spawn(player.getX(), player.getY());
  player.spawn();
  deathTimer = 360;
  clouds.resetMap();
  deathSoundPlayed = false; 
}
