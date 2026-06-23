#pragma once

#include "Data.hpp"

class Player {
  private:
    Data::FieldState color;
    int capturedPrisoners;

  public:
    Player();
    Player(Data::FieldState color);

    void addPrisoners(int count);
    int getScore();
    void setColor(Data::FieldState playerColor);
};