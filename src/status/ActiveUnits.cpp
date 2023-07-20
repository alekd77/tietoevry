#include "ActiveUnits.h"

ActiveUnits::ActiveUnits(const Base& base,
        std::vector<std::unique_ptr<CombatUnit>> activeCombatUnits)
        :base(base), activeCombatUnits(std::move(activeCombatUnits)) { }

Base& ActiveUnits::getBase() { return base; }

std::vector<std::unique_ptr<CombatUnit>>& ActiveUnits::getActiveCombatUnits()
{
    return activeCombatUnits;
}

bool ActiveUnits::isBaseBuildingUnit() const
{
    return base.getBuildingUnit()!='0';
}
