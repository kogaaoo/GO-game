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

    Player();
    Player(Data::FieldState color) :color(color), capturedPrisoners(0) {}
};