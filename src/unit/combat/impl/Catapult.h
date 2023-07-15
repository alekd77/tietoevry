#ifndef TIETOEVRY_CATAPULT_H
#define TIETOEVRY_CATAPULT_H

#include "../CombatUnit.h"

class Catapult : public CombatUnit {
public:
  Catapult(int id, const FieldCoordinates &coordinates);
  Catapult(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_CATAPULT_H
