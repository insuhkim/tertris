#include "coord.hpp"

Coord::Coord(int x, int y) : x(x), y(y) {}
Coord::Coord() : x(0), y(0) {}

Coord Coord::operator+(const Coord &other) const {
  return {x + other.x, y + other.y};
}

Coord Coord::operator-(const Coord &other) const {
  return {x - other.x, y - other.y};
}

Coord Coord::operator+=(const Coord &other) {
  x += other.x;
  y += other.y;
  return *this;
}

Coord Coord::operator-=(const Coord &other) {
  x -= other.x;
  y -= other.y;
  return *this;
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

void Coord::rotate180(Coord pivot) {
  int nx = pivot.x - (x - pivot.x);
  int ny = pivot.y - (y - pivot.y);
  x = nx;
  y = ny;
}
