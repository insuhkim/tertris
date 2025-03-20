#include "coord.hpp"

Coord::Coord(int x, int y) : x(x), y(y) {}
Coord::Coord() : x(0), y(0) {}

Coord Coord::operator+(const Coord &other) const {
  return {x + other.x, y + other.y};
}
Coord Coord::operator-(const Coord &other) const {
  return {x - other.x, y - other.y};
}
void Coord::rotateCW(Coord pivot) {
  int nx = pivot.x + (y - pivot.y);
  int ny = pivot.y - (x - pivot.x);
  x = nx;
  y = ny;
}
void Coord::rotateCCW(Coord pivot) {
  int nx = pivot.x - (y - pivot.y);
  int ny = pivot.y + (x - pivot.x);
  x = nx;
  y = ny;
}
