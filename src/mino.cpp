#include "mino.hpp"

Mino::Mino(Mino::Type type) : type(type) {
  switch (type) {
  case Type::I:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 0), Coord(1, 0), Coord(2, 0)};
    break;
  case Type::O:
    center = Coord(0, 0);
    relativeCoords = {Coord(0, 1), Coord(1, 1), Coord(1, 0)};
    break;
  case Type::T:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 0), Coord(1, 0), Coord(0, 1)};
    break;
  case Type::S:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 0), Coord(0, 1), Coord(1, 1)};
    break;
  case Type::Z:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 1), Coord(0, 1), Coord(1, 0)};
    break;
  case Type::J:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 0), Coord(1, 0), Coord(1, 1)};
    break;
  case Type::L:
    center = Coord(0, 0);
    relativeCoords = {Coord(-1, 1), Coord(-1, 0), Coord(1, 0)};
    break;
  }
}

std::vector<Coord> Mino::getCoords() const {
  std::vector<Coord> cells = {center};
  for (const Coord &relativeCoord : relativeCoords)
    cells.push_back(center + relativeCoord);
  return cells;
}

void Mino::moveRight() { center.x++; }

void Mino::moveLeft() { center.x--; }

void Mino::moveDown() { center.y++; }

void Mino::moveUp() { center.y--; }

void Mino::moveRight(int n) { center.x += n; }

void Mino::moveLeft(int n) { center.x -= n; }

void Mino::moveDown(int n) { center.y += n; }

void Mino::moveUp(int n) { center.y -= n; }

void Mino::rotateCW(Coord offset) {
  center += offset;
  for (Coord &relativeCoord : relativeCoords) {
    relativeCoord.rotateCW();
  }
  switch (rotationState) {
  case rotationState::Spawn:
    rotationState = rotationState::CW;
    break;
  case rotationState::CW:
    rotationState = rotationState::_180;
    break;
  case rotationState::CCW:
    rotationState = rotationState::Spawn;
    break;
  case rotationState::_180:
    rotationState = rotationState::CCW;
    break;
  }
}

void Mino::rotateCCW(Coord offset) {
  center += offset;
  for (Coord &relativeCoord : relativeCoords) {
    relativeCoord.rotateCCW();
  }
  switch (rotationState) {
  case rotationState::Spawn:
    rotationState = rotationState::CCW;
    break;
  case rotationState::CW:
    rotationState = rotationState::Spawn;
    break;
  case rotationState::CCW:
    rotationState = rotationState::_180;
    break;
  case rotationState::_180:
    rotationState = rotationState::CW;
    break;
  }
}

void Mino::rotate180(Coord offset) {
  center += offset;
  for (Coord &relativeCoord : relativeCoords) {
    relativeCoord.rotate180();
  }
  switch (rotationState) {
  case rotationState::Spawn:
    rotationState = rotationState::_180;
    break;
  case rotationState::CW:
    rotationState = rotationState::CCW;
    break;
  case rotationState::CCW:
    rotationState = rotationState::CW;
    break;
  case rotationState::_180:
    rotationState = rotationState::Spawn;
    break;
  }
}
