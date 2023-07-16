#ifndef TIETOEVRY_SWORDSMAN_H
#define TIETOEVRY_SWORDSMAN_H

#include "../CombatUnit.h"

class Swordsman : public CombatUnit {
public:
    Swordsman(int id, const FieldCoordinates& coordinates);

    Swordsman(int id, int hp, const FieldCoordinates& coordinates);

    int calculateDamageForUnitType(char targetUnitType) const override;
};

#endif // TIETOEVRY_SWORDSMAN_H
