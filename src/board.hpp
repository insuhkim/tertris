#ifndef BOARD_HPP
#define BOARD_HPP

#include "mino.hpp"
#include <vector>

class Board {
public:
  enum class CellType { Empty, I, O, T, S, Z, J, L, Garbage };
  Board(int width, int height);
  void clear();
  bool isOccupied(int x, int y) const;
  bool isValidPosition(const Mino &mino) const;
  void placeMino(const Mino &mino);
  void removeFullLines();

private:
  int width;
  int height;
  int actualHeight;
  int lineClearedCount;
  int blockPlacedCount;
  int maxExistingY;
  std::vector<std::vector<CellType>> board;
};

#endif // BOARD_HPP
