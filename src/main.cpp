#include "../include/GO-game/GameEngine.hpp"
#include "../include/GO-game/ConsoleView.hpp"

int main() {
  ConsoleView view;
  
  // 1. Najpierw pytamy gracza o rozmiar planszy
  int chosenSize = view.displayMenu();
  
  // 2. TWORZYMY silnik gry, podając mu wybrany rozmiar od razu na starcie!
  GameEngine game(chosenSize);
  
  // 3. Uruchamiamy grę
  game.start();
  game.runLoop();
  
  return 0;
}