#include "Knight.h"

Knight::Knight(int id, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'K', 70, coordinates, 5, 400, 1, 5) {}

Knight::Knight(int id, int hp, const FieldCoordinates &coordinates)
    : CombatUnit(id, 'K', hp, coordinates, 5, 400, 1, 5) {}

int Knight::calculateDamageForUnitType(char targetUnitType) const {
  switch (targetUnitType) {
  case 'K':
    return 35;
  case 'S':
    return 35;
  case 'A':
    return 35;
  case 'P':
    return 35;
  case 'C':
    return 35;
  case 'R':
    return 50;
  case 'W':
    return 35;
  case 'B':
    return 35;
  default:
    return 0;
  }
}
