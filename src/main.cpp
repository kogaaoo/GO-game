#include "../include/GO-game/GameEngine.hpp"
#include "../include/GO-game/ConsoleView.hpp"

int main() {
  ConsoleView view;
  
  int chosenSize = view.displayMenu();
  
  GameEngine game(chosenSize);
  
  game.start();
  game.runLoop();
  
  return 0;
}