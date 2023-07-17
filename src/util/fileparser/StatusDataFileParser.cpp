#include "StatusDataFileParser.h"
#include "../../unit/combat/impl/Knight.h"
#include "../../unit/combat/impl/Swordsman.h"
#include "../../unit/combat/impl/Archer.h"
#include "../../unit/combat/impl/Pikeman.h"
#include "../../unit/combat/impl/Ram.h"
#include "../../unit/combat/impl/Catapult.h"
#include "../../unit/combat/impl/Worker.h"
#include <sstream>

StatusDataFileParser::StatusDataFileParser(const std::string& dataFile)
        :DataFileParser(dataFile)
{
    // Initialize the combatUnitTypeMap with lambdas for creating each combat unit type
    combatUnitTypeMap = {
            {'K', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Knight>(id, hp, coords);
            }},
            {'S', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Swordsman>(id, hp, coords);
            }},
            {'A', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Archer>(id, hp, coords);
            }},
            {'P', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Pikeman>(id, hp, coords);
            }},
            {'R', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Ram>(id, hp, coords);
            }},
            {'C', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Catapult>(id, hp, coords);
            }},
            {'W', [](int id, int hp, FieldCoordinates coords) {
                return std::make_unique<Worker>(id, hp, coords);
            }}
    };
}

long StatusDataFileParser::parseCurrentGoldAmount()
{
    // Extract the current amount of gold from the first line of the status.txt file
    long currentGoldAmount = std::stol(dataFileLines.at(0));

    return currentGoldAmount;
}

ActiveUnits StatusDataFileParser::parsePlayerUnits()
{
    // Parse and retrieve the active units for the player affiliation
    return parseUnitsForAffiliation('P');
}

ActiveUnits StatusDataFileParser::parseEnemyUnits()
{
    // Parse and retrieve the active units for the enemy affiliation
    return parseUnitsForAffiliation('E');
}

ActiveUnits StatusDataFileParser::parseUnitsForAffiliation(char affiliation)
{
    std::unique_ptr<Base> base = nullptr;
    std::vector<std::unique_ptr<CombatUnit>> activeCombatUnits;

    // Start parsing the status description of the units from the second line of the status.txt file
    for (int i = 1; i<dataFileLines.size(); ++i) {
        // status.txt line format: affiliation, type, id, xCoord, yCoord, hp, buildingUnit (for base)
        std::string line = dataFileLines.at(i);
        std::istringstream iss(line);
        char unitAffiliation;
        iss >> unitAffiliation;

        if (unitAffiliation!=affiliation) {
            continue;   // Skip the line if the unit affiliation doesn't match the desired affiliation
        }

        char unitType;
        int unitID;
        int unitXCoordinate;
        int unitYCoordinate;
        int unitHP;
        iss >> unitType >> unitID >> unitXCoordinate >> unitYCoordinate
            >> unitHP;

        if (unitType=='B') {
            char buildingUnit;
            iss >> buildingUnit;
            base = std::make_unique<Base>(unitID, unitHP,
                    FieldCoordinates(unitXCoordinate, unitYCoordinate),
                    buildingUnit);
        } else if (combatUnitTypeMap.count(unitType)) {
            activeCombatUnits.push_back(
                    combatUnitTypeMap[unitType](unitID, unitHP,
                            FieldCoordinates(unitXCoordinate,
                                    unitYCoordinate)));
        }
    }

    // If no base unit is found, it indicates a missing or incomplete status description in the status.txt file.
    if (!base) {
        throw std::runtime_error("Failed to parse units.\n");
    }

    return {*base, std::move(activeCombatUnits)};
}
