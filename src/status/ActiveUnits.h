#ifndef TIETOEVRY_SRC_STATUS_ACTIVEUNITS_H_
#define TIETOEVRY_SRC_STATUS_ACTIVEUNITS_H_

#include "../unit/builder/impl/Base.h"
#include "../unit/combat/CombatUnit.h"
#include <memory>
#include <vector>

class ActiveUnits {
public:
    ActiveUnits(const Base& base,
            std::vector<std::unique_ptr<CombatUnit>> activeCombatUnits);

    const Base& getBase() const;

    const std::vector<std::unique_ptr<CombatUnit>>&
    getActiveCombatUnits() const;

    bool isBaseBuildingUnit() const;

private:
    Base base;
    std::vector<std::unique_ptr<CombatUnit>> activeCombatUnits;
};

#endif // TIETOEVRY_SRC_STATUS_ACTIVEUNITS_H_
