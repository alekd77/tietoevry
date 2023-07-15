#ifndef TIETOEVRY_COMBATUNIT_H
#define TIETOEVRY_COMBATUNIT_H

#include "Unit.h"

class CombatUnit : public Unit {
public:
  CombatUnit(int id, char type, int hp, const FieldCoordinates &coordinates,
             int actionPoints, int cost, int range, int buildTime);

  int getActionPoints() const;

  int getCost() const;

  int getRange() const;

  int getBuildTime() const;

  bool canMove() const override;

  bool canAttack() const override;

  bool canBuild() const override;

  void debugDisplay() const override;

  virtual int calculateDamageForUnitType(char targetUnitType) const = 0;

private:
  int actionPoints;
  int cost;
  int range;
  int buildTime;
};

#endif // TIETOEVRY_COMBATUNIT_H
