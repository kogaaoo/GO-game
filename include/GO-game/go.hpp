#pragma once

#include <array>
#include <vector>

namespace Data {
  enum class Fieldstate {
    EMPTY,
    BLACK,
    WHITE
  };

  struct Position {
    int x;
    int y;
  };
}

class Board {
  private:
    int size;
    std::vector<std::vector<Data::Fieldstate>> grid;
     
  public:
    bool isValidMove(Data::Position pos, Data::Fieldstate color);
    
    void placeStone(Data::Position pos, Data::Fieldstate color);
    void captureDeadStone(Data::Position lastMove);
    void getLibertiesCount(Data::Position pos);
};

class Player {
  private:
    Data::Fieldstate color;
    int capturedPrisoners;

  public:
    void addPrisoners(int count);

    int getScore();
};

class GameEngine {
  private:
    Board board;

    std::array<Player, 2> players;

    bool activePlayerIndex;
    int consecutivePasses;
  public:
    void start();
    void runLoop();
    void handlePass();
    float calculateFinalScore();
};

class ConsoleView {
    public:
      void displayMenu();
      void drawBoard();
      void readMove();
      void showStats(Player p1, Player p2);
};