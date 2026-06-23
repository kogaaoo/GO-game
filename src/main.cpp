#include "../include/GO-game/GameEngine.hpp"

int main() {
  GameEngine game;
  
  game.start();
  game.runLoop();
  
  return 0;
}