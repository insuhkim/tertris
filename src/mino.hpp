#ifndef MINOS_HPP
#define MINOS_HPP

#include "coord.hpp"
#include <vector>

class Mino {
public:
  const enum class Type { I, O, T, S, Z, J, L } type;
  enum class rotationState { Spawn, CW, CCW, _180 } rotationState;
  Mino(Type type);
  bool rotateCW();
  bool rotateCCW();
  bool rotate180();
  bool tryRotateCW();
  bool tryRotateCCW();
  bool tryRotate180();

private:
  Coord center;
  std::vector<Coord> relativeCells;
};

#endif // MINOS_HPP
