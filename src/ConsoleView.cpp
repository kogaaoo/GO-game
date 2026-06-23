#include <iostream>
#include <string>
#include <cctype>
#include "../include/GO-game/ConsoleView.hpp"

ConsoleView::ConsoleView() {
}

void ConsoleView::displayMenu() {
  std::cout << "==============================\n";
  std::cout << "          GRA W GO            \n";
  std::cout << "==============================\n";
  std::cout << "Wybierz rozmiar planszy, aby rozpocząć:\n";
  std::cout << " - 9  (9x9)\n";
  std::cout << " - 13 (13x13)\n";
  std::cout << " - 19 (19x19)\n";
  std::cout << "Wprowadź rozmiar: ";
}

void ConsoleView::drawBoard(Board board) {
  std::cout << "\n   ";
  // Rysowanie nagłówków kolumn (A, B, C...)
  for (int x = 0; x < board.getSize(); ++x) {
    std::cout << (char)('A' + x) << " ";
  }
  std::cout << "\n";

  // Rysowanie rzędów wraz z ich numerami
  for (int y = 0; y < board.getSize(); ++y) {
    // Wyrównanie numeracji rzędów (dodatkowa spacja dla jednocyfrowych)
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

// Pobiera współrzędne od gracza i parsuje je na strukturę Position lub obsługuje "pass"
std::optional<Data::Position> ConsoleView::readMove() {
  std::string input;
  std::cout << "Podaj ruch (np. d4) lub wpisz 'pass': ";
  std::cin >> input;

  // Konwersja wpisanego tekstu na małe litery w celu ułatwienia parsowania
  for (char &c : input) {
    c = std::tolower(c);
  }

  // Obsługa spasowania tury przez gracza
  if (input == "pass") {
    return std::nullopt;
  }

  if (input.empty()) {
    return Data::Position(-1, -1);
  }

  // Parsowanie kolumny (litera, np. 'd')
  char colChar = input[0];
  if (colChar < 'a' || colChar > 'z') {
    std::cout << "[Widok] Niepoprawna litera kolumny!\n";
    return Data::Position(-1, -1); // Zwracamy błędną pozycję, GameEngine ją odrzuci
  }
  int x = colChar - 'a';

  // Parsowanie rzędu (liczba, np. "4")
  try {
    std::string rowPart = input.substr(1);
    int rowNum = std::stoi(rowPart);
    int y = rowNum - 1; // Konwersja na indeks tablicy (od 0)
    return Data::Position(x, y);
  } catch (...) {
    std::cout << "[Widok] Niepoprawny format numeru rzędu!\n";
    return Data::Position(-1, -1);
  }
}

// Wyświetla na ekranie aktualną liczbę jeńców
void ConsoleView::showStats(Player p1, Player p2) {
  std::cout << "==============================\n";
  std::cout << "          STATYSTYKI          \n";
  std::cout << "==============================\n";
  std::cout << " Gracz 1 (Czarne) X -> Jeńcy: " << p1.getScore() << "\n";
  std::cout << " Gracz 2 (Białe)  O -> Jeńcy: " << p2.getScore() << "\n";
  std::cout << "==============================\n";
}