#include "../include/GO-game/Board.hpp"
#include <queue>
#include <set>

Board::Board() : size(19), grid(19, std::vector<Data::FieldState>(19, Data::FieldState::EMPTY)) {}
Board::Board(int boardSize) : size(boardSize), grid(boardSize, std::vector<Data::FieldState>(boardSize, Data::FieldState::EMPTY)) {}

int Board::getSize() {
  return size;
}

std::vector<std::vector<Data::FieldState>> Board::getGrid() {
  return grid;
}

bool Board::isValidMove(Data::Position pos, Data::FieldState color) {
  if (pos.x < 0 || pos.x >= size || pos.y < 0 || pos.y >= size) {
    return false;
  }

  if (grid[pos.y][pos.x] != Data::FieldState::EMPTY) {
    return false;
  }

  grid[pos.y][pos.x] = color;
  int liberties = getLibertiesCount(pos);
  grid[pos.y][pos.x] = Data::FieldState::EMPTY;

  if (liberties > 0) {
    return true;
  }

  Data::FieldState opponentColor = (color == Data::FieldState::BLACK) ? Data::FieldState::WHITE : Data::FieldState::BLACK;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  for (int i = 0; i < 4; ++i) {
    int nx = pos.x + dx[i];
    int ny = pos.y + dy[i];

    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
      if (grid[ny][nx] == opponentColor) {
        if (getLibertiesCount(Data::Position(nx, ny)) == 1) {
          return true; 
        }
      }
    }
  }

  return false;
}

void Board::placeStone(Data::Position pos, Data::FieldState color) {
  if (pos.x >= 0 && pos.x < size && pos.y >= 0 && pos.y < size) {
    grid[pos.y][pos.x] = color;
  }
}

int Board::captureDeadStones(Data::Position lastMove) {
  Data::FieldState playerColor = grid[lastMove.y][lastMove.x];
  if (playerColor == Data::FieldState::EMPTY) return 0;

  Data::FieldState opponentColor = (playerColor == Data::FieldState::BLACK) ? Data::FieldState::WHITE : Data::FieldState::BLACK;
  int totalCaptured = 0;

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  for (int i = 0; i < 4; ++i) {
    int nx = lastMove.x + dx[i];
    int ny = lastMove.y + dy[i];

    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
      if (grid[ny][nx] == opponentColor) {
        if (getLibertiesCount(Data::Position(nx, ny)) == 0) {
          
          std::queue<Data::Position> queue;
          std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));
          
          queue.push(Data::Position(nx, ny));
          visited[ny][nx] = true;

          while (!queue.empty()) {
            Data::Position current = queue.front();
            queue.pop();

            grid[current.y][current.x] = Data::FieldState::EMPTY;
            totalCaptured++;

            for (int j = 0; j < 4; ++j) {
              int mx = current.x + dx[j];
              int my = current.y + dy[j];

              if (mx >= 0 && mx < size && my >= 0 && my < size) {
                if (grid[my][mx] == opponentColor && !visited[my][mx]) {
                  visited[my][mx] = true;
                  queue.push(Data::Position(mx, my));
                }
              }
            }
          }

        }
      }
    }
  }

  return totalCaptured;
}

// Przeszukuje planszę (BFS) w celu zliczenia pustych pól wokół grupy
int Board::getLibertiesCount(Data::Position pos) {
  Data::FieldState targetColor = grid[pos.y][pos.x];
  if (targetColor == Data::FieldState::EMPTY) return 0;

  std::queue<Data::Position> queue;
  std::set<std::pair<int, int>> liberties;
  std::vector<std::vector<bool>> visited(size, std::vector<bool>(size, false));

  queue.push(pos);
  visited[pos.y][pos.x] = true;

  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  while (!queue.empty()) {
    Data::Position current = queue.front();
    queue.pop();

    for (int i = 0; i < 4; ++i) {

      int nx = current.x + dx[i];
      int ny = current.y + dy[i];

      if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
        if (grid[ny][nx] == Data::FieldState::EMPTY) {
          liberties.insert({nx, ny});
        } else if (grid[ny][nx] == targetColor && !visited[ny][nx]) {
          visited[ny][nx] = true;
          queue.push(Data::Position(nx, ny));
        }
      }
    }
  }

  return liberties.size();
}