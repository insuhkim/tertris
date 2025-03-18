#ifndef MINOS_HPP
#define MINOS_HPP

#include "cell.hpp"
#include <vector>

class Mino {
public:
  enum class minoType { I, O, T, S, Z, J, L };
  enum class rotationState { Zero, Ninety, OneEighty, TwoSeventy };
  Mino(minoType type);

private:
  const minoType type;
  rotationState rotationState;
  std::vector<Cell> cells;
};

#endif // MINOS_HPP
