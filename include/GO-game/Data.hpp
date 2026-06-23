#pragma once

namespace Data {
  enum class FieldState {
    EMPTY,
    BLACK,
    WHITE
  };

  struct Position {
    int x;
    int y;

    Position(int x, int y) : x(x), y(y) {}
  };
}