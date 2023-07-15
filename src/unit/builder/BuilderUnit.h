#ifndef TIETOEVRY_BUILDERUNIT_H
#define TIETOEVRY_BUILDERUNIT_H

#include "../Unit.h"

class BuilderUnit : public Unit {
public:
  BuilderUnit(int id, char type, int hp, const FieldCoordinates &coordinates,
              char buildingUnit, int buildRemainingTurns);

  char getBuildingUnit() const;
  int getBuildRemainingTurns() const;

  bool canMove() const override;
  bool canAttack() const override;
  bool canBuild() const override;
  void debugDisplay() const override;

private:
  char buildingUnit;
  int buildRemainingTurns;
};

#endif // TIETOEVRY_BUILDERUNIT_H
