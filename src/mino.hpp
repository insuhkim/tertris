#ifndef MINOS_HPP
#define MINOS_HPP

#include "coord.hpp"
#include <vector>

class Mino {
public:
  const enum class Type { I, O, T, S, Z, J, L } type;
  enum class rotationState { Spawn, CW, CCW, _180 } rotationState;
  Mino(Type type);
  std::vector<Coord> getCoords() const;
  void moveRight();
  void moveLeft();
  void moveDown();
  void moveUp();
  void moveRight(int n);
  void moveLeft(int n);
  void moveDown(int n);
  void moveUp(int n);

  void rotateCW(Coord offset = {0, 0});
  void rotateCCW(Coord offset = {0, 0});
  void rotate180(Coord offset = {0, 0});

private:
  Coord center;
  std::vector<Coord> relativeCoords;
};

#endif // MINOS_HPP
