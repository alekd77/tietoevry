#ifndef TIETOEVRY_FIELDCOORDINATES_H
#define TIETOEVRY_FIELDCOORDINATES_H

class FieldCoordinates {
public:
  FieldCoordinates(int x, int y);

  int getX() const;
  int getY() const;

private:
  int x;
  int y;
};

#endif // TIETOEVRY_FIELDCOORDINATES_H
