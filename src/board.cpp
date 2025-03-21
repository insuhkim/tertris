#include "board.hpp"
#include <algorithm>

Board::Board(int width, int height)
    : width(width), height(height), actualHeight(height * 2 + 2),
      board(height * 2 + 2, std::vector<CellType>(width)) {
  clear();

  /*    |         |     */
  /*    |         |     */
  /*    |         |     */
  /*    +---------+     */
  /*  origin            */
}

void Board::clear() {
  for (auto &row : board) {
    std::fill(row.begin(), row.end(), CellType::Empty);
  }
  lineClearedCount = 0;
  blockPlacedCount = 0;
  maxExistingY = -1;
}

bool Board::isOccupied(int x, int y) const {
  return board[y][x] != CellType::Empty;
}

bool Board::isValidPosition(const Mino &mino) const {
  for (auto &coord : mino.getCoords()) {
    if (coord.y >= actualHeight) {
      return false;
    }
    if (coord.x < 0 || coord.x >= width) {
      return false;
    }
    if (isOccupied(coord.x, coord.y)) {
      return false;
    }
  }
  return true;
}

void Board::placeMino(const Mino &mino) {
  if (!isValidPosition(mino)) {
    return;
  }
  CellType CT = mino.type == Mino::Type::I   ? CellType::I
                : mino.type == Mino::Type::O ? CellType::O
                : mino.type == Mino::Type::T ? CellType::T
                : mino.type == Mino::Type::S ? CellType::S
                : mino.type == Mino::Type::Z ? CellType::Z
                : mino.type == Mino::Type::J ? CellType::J
                : mino.type == Mino::Type::L ? CellType::L
                                             : CellType::Empty;

  for (auto &coord : mino.getCoords()) {
    board[coord.y][coord.x] = CT;
    maxExistingY = std::max(maxExistingY, coord.y);
  }

  blockPlacedCount++;
}

void Board::removeFullLines() {
  int lineClearedTemp = 0;
  for (int y = 0; y <= maxExistingY; y++) {
    // check if the line is full
    if (std::all_of(board[y].begin(), board[y].end(),
                    [](CellType cell) { return cell != CellType::Empty; })) {
      lineClearedTemp++;
    } else {
      // copy the line to the new position
      board[y - lineClearedTemp] = board[y];
      // clear the old line
      board[y].assign(width, CellType::Empty);
    }
  }
  lineClearedCount += lineClearedTemp;
  maxExistingY -= lineClearedTemp;
}
