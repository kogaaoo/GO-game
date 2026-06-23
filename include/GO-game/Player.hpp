#pragma once

#include "Data.hpp"

class Player {
  private:
    Data::FieldState color;
    int capturedPrisoners;

  public:
    void addPrisoners(int count);
    int getScore();
    void setColor(Data::FieldState playerColor);

    Player(Data::FieldState color);
};