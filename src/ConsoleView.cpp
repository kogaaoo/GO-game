#include <iostream>
#include <string>
#include <cctype>
#include "../include/GO-game/ConsoleView.hpp"

ConsoleView::ConsoleView() {}

int ConsoleView::displayMenu() {
  int size = 0;
  
  while (true) {
    std::cout << "==============================\n";
    std::cout << "          GRA W GO            \n";
    std::cout << "==============================\n";
    std::cout << "Wybierz rozmiar planszy, aby rozpocząć:\n";
    std::cout << " - 9  (9x9)\n";
    std::cout << " - 13 (13x13)\n";
    std::cout << " - 19 (19x19)\n";
    std::cout << "Wprowadź rozmiar: ";
    
    std::cin >> size;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "[Widok] Niepoprawny format. Wpisz liczbe!\n\n";
    } 
    else if (size == 9 || size == 13 || size == 19) {
      return size;
    } else {
      std::cout << "[Widok] Nieznany rozmiar. Wybierz 9, 13 lub 19!\n\n";
    }
  }
}

void ConsoleView::drawBoard(Board board) {
  std::cout << "\n   ";
  for (int x = 0; x < board.getSize(); ++x) {
    std::cout << (char)('A' + x) << " ";
  }
  std::cout << "\n";

  for (int y = 0; y < board.getSize(); ++y) {
    if (y + 1 < 10) {
      std::cout << " ";
    }
    std::cout << y + 1 << " ";

    for (int x = 0; x < board.getSize(); ++x) {
      Data::FieldState state = board.getGrid()[y][x];
      if (state == Data::FieldState::BLACK) {
        std::cout << "X ";
      } else if (state == Data::FieldState::WHITE) {
        std::cout << "O ";
      } else {
        std::cout << ". ";
      }
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

std::optional<Data::Position> ConsoleView::readMove() {
  std::string input;
  std::cout << "Podaj ruch (np. d4) lub wpisz 'pass': ";
  std::cin >> input;

  for (char &c : input) {
    c = std::tolower(c);
  }

  if (input == "pass") {
    return std::nullopt;
  }

  if (input.empty()) {
    return Data::Position(-1, -1);
  }

  char colChar = input[0];
  if (colChar < 'a' || colChar > 'z') {
    std::cout << "[Widok] Niepoprawna litera kolumny!\n";
    return Data::Position(-1, -1);
  }
  int x = colChar - 'a';

  try {
    std::string rowPart = input.substr(1);
    int rowNum = std::stoi(rowPart);
    int y = rowNum - 1;
    return Data::Position(x, y);
  } catch (...) {
    std::cout << "[Widok] Niepoprawny format numeru rzędu!\n";
    return Data::Position(-1, -1);
  }
}

void ConsoleView::showStats(Player p1, Player p2) {
  std::cout << "==============================\n";
  std::cout << "          STATYSTYKI          \n";
  std::cout << "==============================\n";
  std::cout << " Gracz 1 (Czarne) X -> Jeńcy: " << p1.getScore() << "\n";
  std::cout << " Gracz 2 (Białe)  O -> Jeńcy: " << p2.getScore() << "\n";
  std::cout << "==============================\n";
}