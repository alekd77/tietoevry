#ifndef TIETOEVRY_ARCHER_H
#define TIETOEVRY_ARCHER_H

#include "../CombatUnit.h"

class Archer : public CombatUnit {
public:
  Archer(int id, const FieldCoordinates &coordinates);
  Archer(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_ARCHER_H
