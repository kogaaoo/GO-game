#pragma once

#include <optional>
#include "Board.hpp"
#include "Player.hpp"

class ConsoleView {
    public:
      ConsoleView();

      int displayMenu();
      void drawBoard(Board board);
      std::optional<Data::Position> readMove();
      void showStats(Player p1, Player p2);
};