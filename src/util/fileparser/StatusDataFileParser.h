#ifndef TIETOEVRY_SRC_UTIL_STATUSDATAFILEREADER_H_
#define TIETOEVRY_SRC_UTIL_STATUSDATAFILEREADER_H_

#include "DataFileParser.h"
#include "../../status/ActiveUnits.h"
#include <map>
#include <functional>

class StatusDataFileParser : public DataFileParser {
public:
    explicit StatusDataFileParser(const std::string& dataFile);

    long parseCurrentGoldAmount();

    ActiveUnits parsePlayerUnits();

    ActiveUnits parseEnemyUnits();

private:
    std::map<char, std::function<std::unique_ptr<CombatUnit>(int, int,
            FieldCoordinates)>> combatUnitTypeMap;

    ActiveUnits parseUnitsForAffiliation(char affiliation);
};

#endif // TIETOEVRY_SRC_UTIL_STATUSDATAFILEREADER_H_
