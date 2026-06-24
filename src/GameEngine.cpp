#include "../include/GO-game/GameEngine.hpp"
#include "../include/GO-game/ConsoleView.hpp" 

GameEngine::GameEngine(int boardSize) : board(boardSize), activePlayerIndex(0), consecutivePasses(0) {
}

void GameEngine::start() {
    players[0].setColor(Data::FieldState::BLACK);
  players[1].setColor(Data::FieldState::WHITE);
  
  activePlayerIndex = 0; 
  consecutivePasses = 0;
}

void GameEngine::runLoop() {
  ConsoleView view;
  bool gameRunning = true;

  while (gameRunning) {
    view.drawBoard(board);
    view.showStats(players[0], players[1]);

    std::optional<Data::Position> move = view.readMove();

    if (!move.has_value()) {
      handlePass();
      if (consecutivePasses >= 2) {
        gameRunning = false;
      }
    } else {
      consecutivePasses = 0;

      Data::FieldState currentPlayerColor = (activePlayerIndex == 0) ? Data::FieldState::BLACK : Data::FieldState::WHITE;

      if (board.isValidMove(move.value(), currentPlayerColor)) {
        board.placeStone(move.value(), currentPlayerColor);
        
        int captured = board.captureDeadStones(move.value());
        players[activePlayerIndex].addPrisoners(captured);
      } else {
        continue; 
      }
    }

    if (gameRunning) {
      activePlayerIndex = (activePlayerIndex == 0) ? 1 : 0;
    }
  }

  float finalScore = calculateFinalScore();
}

void GameEngine::handlePass() {
  consecutivePasses++;
}

float GameEngine::calculateFinalScore() {

  // algorytm zliczający punkty
  float scorePlayer1 = players[0].getScore();
  float scorePlayer2 = players[1].getScore() + 6.5f; // Komi dla białych
  
  return scorePlayer1 - scorePlayer2; 
}