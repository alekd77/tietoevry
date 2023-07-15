#include "Ram.h"

Ram::Ram(int id, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'R', 90, coordinates, 2, 500, 1, 4) {}

Ram::Ram(int id, int hp, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'R', hp, coordinates, 2, 500, 1, 4) {}

int Ram::calculateDamageForUnitType(char targetUnitType) const {
  switch (targetUnitType) {
  case 'K':
    return 10;
  case 'S':
    return 10;
  case 'A':
    return 10;
  case 'P':
    return 10;
  case 'C':
    return 10;
  case 'R':
    return 10;
  case 'W':
    return 10;
  case 'B':
    return 50;
  default:
    return 0;
  }
}