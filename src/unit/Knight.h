#ifndef TIETOEVRY_KNIGHT_H
#define TIETOEVRY_KNIGHT_H

#include "CombatUnit.h"

class Knight : public CombatUnit {
public:
  Knight(int id, const FieldCoordinates &coordinates);
  Knight(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_KNIGHT_H
