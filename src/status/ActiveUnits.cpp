#include "ActiveUnits.h"

ActiveUnits::ActiveUnits(const Base& base,
        std::vector<std::unique_ptr<CombatUnit>> activeCombatUnits)
        :base(base), activeCombatUnits(std::move(activeCombatUnits)) { }

const Base& ActiveUnits::getBase() const { return base; }

const std::vector<std::unique_ptr<CombatUnit>>&
ActiveUnits::getActiveCombatUnits() const
{
    return activeCombatUnits;
}

bool ActiveUnits::isBaseBuildingUnit() const
{
    return base.getBuildingUnit()!='0';
}
