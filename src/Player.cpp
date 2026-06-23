#include "../include/GO-game/Player.hpp"

Player::Player() : color(Data::FieldState::EMPTY), capturedPrisoners(0) {}
Player::Player(Data::FieldState color) : color(color), capturedPrisoners(0) {}

void Player::addPrisoners(int count) {
  capturedPrisoners += count;
}

int Player::getScore() {
  return capturedPrisoners;
}

void Player::setColor(Data::FieldState playerColor) {
  color = playerColor;
}