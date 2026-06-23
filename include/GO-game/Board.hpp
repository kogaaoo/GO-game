#pragma once

#include <vector>
#include "Data.hpp"

class Board {
  private:
    int size;
    std::vector<std::vector<Data::FieldState>> grid;
     
  public:
    Board();
    Board(int size);

    int getSize();
    std::vector<std::vector<Data::FieldState>> getGrid();

    bool isValidMove(Data::Position pos, Data::FieldState color);
    
    void placeStone(Data::Position pos, Data::FieldState color);
    int captureDeadStones(Data::Position lastMove);
    int getLibertiesCount(Data::Position pos);
};