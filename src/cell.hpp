#ifndef BLOCK_HPP
#define BLOCK_HPP

struct Color {
  int r;
  int g;
  int b;
};

class Cell {
public:
  Cell(int x, int y, Color color);
  int x;
  int y;
  Color color;
};

#endif // BLOCK_HPP
