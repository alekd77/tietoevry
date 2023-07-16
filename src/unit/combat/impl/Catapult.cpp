#include "Catapult.h"

Catapult::Catapult(int id, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'C', 50, coordinates, 2, 800, 7, 6) { }

Catapult::Catapult(int id, int hp, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'C', hp, coordinates, 2, 800, 7, 6) { }

int Catapult::calculateDamageForUnitType(char targetUnitType) const
{
    switch (targetUnitType) {
    case 'K':
        return 40;
    case 'S':
        return 40;
    case 'A':
        return 40;
    case 'P':
        return 40;
    case 'C':
        return 40;
    case 'R':
        return 40;
    case 'W':
        return 40;
    case 'B':
        return 50;
    default:
        return 0;
    }
}
