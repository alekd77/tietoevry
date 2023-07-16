#include "Pikeman.h"

Pikeman::Pikeman(int id, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'P', 50, coordinates, 2, 200, 2, 3) { }

Pikeman::Pikeman(int id, int hp, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'P', hp, coordinates, 2, 200, 2, 3) { }

int Pikeman::calculateDamageForUnitType(char targetUnitType) const
{
    switch (targetUnitType) {
    case 'K':
        return 35;
    case 'S':
        return 15;
    case 'A':
        return 15;
    case 'P':
        return 15;
    case 'C':
        return 15;
    case 'R':
        return 10;
    case 'W':
        return 15;
    case 'B':
        return 10;
    default:
        return 0;
    }
}
