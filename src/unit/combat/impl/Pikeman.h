#ifndef TIETOEVRY_PIKEMAN_H
#define TIETOEVRY_PIKEMAN_H

#include "../CombatUnit.h"

class Pikeman : public CombatUnit {
public:
  Pikeman(int id, const FieldCoordinates &coordinates);
  Pikeman(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_PIKEMAN_H
