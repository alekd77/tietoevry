#ifndef TIETOEVRY_BASE_H
#define TIETOEVRY_BASE_H

#include "../BuilderUnit.h"

class Base : public BuilderUnit {
public:
  Base(int id, const FieldCoordinates &coordinates);
  Base(int id, int hp, const FieldCoordinates &coordinates);
  Base(int id, int hp, const FieldCoordinates &coordinates, char buildingUnit,
       int buildRemainingTurns);
};

#endif // TIETOEVRY_BASE_H
