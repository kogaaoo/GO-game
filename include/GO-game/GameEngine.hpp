#pragma once

#include <array>
#include "Board.hpp"
#include "Player.hpp"

class GameEngine {
  private:
    Board board;

    std::array<Player, 2> players;

    int activePlayerIndex;
    int consecutivePasses;

  public:
    GameEngine(int boardSize);
    
    void start();
    void runLoop();
    void handlePass();
    float calculateFinalScore();
};