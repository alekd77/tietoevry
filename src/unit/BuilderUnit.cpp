#include "BuilderUnit.h"

BuilderUnit::BuilderUnit(int id, char type, int hp,
                         const FieldCoordinates &coordinates, char buildingUnit,
                         int buildRemainingTurns)
    : Unit(id, type, hp, coordinates), buildingUnit(buildingUnit),
      buildRemainingTurns(buildRemainingTurns) {}

char BuilderUnit::getBuildingUnit() const { return buildingUnit; }

int BuilderUnit::getBuildRemainingTurns() const { return buildRemainingTurns; }

bool BuilderUnit::canMove() const { return false; }

bool BuilderUnit::canAttack() const { return false; }

bool BuilderUnit::canBuild() const { return true; }