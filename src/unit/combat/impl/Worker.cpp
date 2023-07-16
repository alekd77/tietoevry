#include "Worker.h"

Worker::Worker(int id, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'W', 20, coordinates, 2, 100, 1, 2) { }

Worker::Worker(int id, int hp, const FieldCoordinates& coordinates)
        :CombatUnit(id, 'W', hp, coordinates, 2, 100, 1, 2) { }

int Worker::calculateDamageForUnitType(char targetUnitType) const
{
    switch (targetUnitType) {
    case 'K':
        return 5;
    case 'S':
        return 5;
    case 'A':
        return 5;
    case 'P':
        return 5;
    case 'C':
        return 5;
    case 'R':
        return 5;
    case 'W':
        return 5;
    case 'B':
        return 1;
    default:
        return 0;
    }
}