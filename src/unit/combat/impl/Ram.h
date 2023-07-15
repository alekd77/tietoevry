#ifndef TIETOEVRY_RAM_H
#define TIETOEVRY_RAM_H

#include "../CombatUnit.h"

class Ram : public CombatUnit {
public:
  Ram(int id, const FieldCoordinates &coordinates);
  Ram(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_RAM_H
