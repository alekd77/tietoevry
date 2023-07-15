#ifndef TIETOEVRY_WORKER_H
#define TIETOEVRY_WORKER_H

#include "../CombatUnit.h"

class Worker : public CombatUnit {
public:
  Worker(int id, const FieldCoordinates &coordinates);
  Worker(int id, int hp, const FieldCoordinates &coordinates);

  int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_WORKER_H
