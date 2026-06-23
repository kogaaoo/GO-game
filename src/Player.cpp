#include "../include/GO-game/Player.hpp"

void Player::addPrisoners(int count) {
  capturedPrisoners += count;
}

int Player::getScore() {
  return capturedPrisoners;
}

void Player::setColor(Data::FieldState playerColor) {
  color = playerColor;
}

Player::Player(Data::FieldState color) : color(color), capturedPrisoners(0) {}