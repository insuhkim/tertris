#include "mino.hpp"

Mino::Mino(Mino::Type type) : type(type) {
  switch (type) {
  case Type::I:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 0), Coord(1, 0), Coord(2, 0)};
    break;
  case Type::O:
    center = Coord(0, 0);
    relativeCells = {Coord(0, 1), Coord(1, 1), Coord(1, 0)};
    break;
  case Type::T:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 0), Coord(1, 0), Coord(0, 1)};
    break;
  case Type::S:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 0), Coord(0, 1), Coord(1, 1)};
    break;
  case Type::Z:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 1), Coord(0, 1), Coord(1, 0)};
    break;
  case Type::J:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 0), Coord(1, 0), Coord(1, 1)};
    break;
  case Type::L:
    center = Coord(0, 0);
    relativeCells = {Coord(-1, 1), Coord(-1, 0), Coord(1, 0)};
    break;
  }
}
