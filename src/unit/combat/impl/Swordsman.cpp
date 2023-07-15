#include "Swordsman.h"

Swordsman::Swordsman(int id, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'S', 60, coordinates, 2, 250, 1, 3) {}

Swordsman::Swordsman(int id, int hp, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'S', hp, coordinates, 2, 250, 1, 3) {}

int Swordsman::calculateDamageForUnitType(char targetUnitType) const {
  switch (targetUnitType) {
  case 'K':
    return 30;
  case 'S':
    return 30;
  case 'A':
    return 30;
  case 'P':
    return 20;
  case 'C':
    return 20;
  case 'R':
    return 30;
  case 'W':
    return 30;
  case 'B':
    return 30;
  default:
    return 0;
  }
}