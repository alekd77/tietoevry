#include "Archer.h"

Archer::Archer(int id, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'A', 40, coordinates, 2, 250, 5, 3) {}

Archer::Archer(int id, int hp, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'A', hp, coordinates, 2, 250, 5, 3) {}

int Archer::calculateDamageForUnitType(char targetUnitType) const {
  switch (targetUnitType) {
  case 'K':
    return 15;
  case 'S':
    return 15;
  case 'A':
    return 15;
  case 'P':
    return 15;
  case 'C':
    return 10;
  case 'R':
    return 10;
  case 'W':
    return 15;
  case 'B':
    return 15;
  default:
    return 0;
  }
}
