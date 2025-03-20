#ifndef COORD_HPP
#define COORD_HPP

class Coord {
public:
  int x;
  int y;
  Coord(int x, int y);
  Coord();

  Coord operator+(const Coord &other) const;
  Coord operator-(const Coord &other) const;
  void rotateCW(Coord pivot = {0, 0});
  void rotateCCW(Coord pivot = {0, 0});
};

#endif // COORD_HPP
