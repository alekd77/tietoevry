#include "AIPlayerFastAttackStrategy.h"
#include "../../../util/pathfinder/BFSPathfinder.h"

AIPlayerFastAttackStrategy::AIPlayerFastAttackStrategy(
        const std::string& mapFile, const std::string& statusFile,
        const std::string& commandsFile)
        :AIPlayer(mapFile, statusFile, commandsFile),
         knightUnitProperties(Knight()) { }

void AIPlayerFastAttackStrategy::gameStrategy()
{
    // the strategy is to produce as many knight-type units
    // as quickly as possible, and then carry out
    // a quick attack on the enemy base

    if (isBuildingKnightPossible()) {
        orderBuildingKnight();
        return;
    } else if (isEnemyBaseAttackPossible()) {
        orderEnemyBaseAttack();
        return;
    } else {
        if (!getPlayerActiveUnits().isBaseBuildingUnit()) {
            orderKnightsMoving();
        }

//        if (isEnemyBaseAttackPossible()) {
//            orderEnemyBaseAttack();
//        }
    }
}

bool AIPlayerFastAttackStrategy::isBuildingKnightPossible() const
{
    return isBuildingUnitPossible(knightUnitProperties);
}

void AIPlayerFastAttackStrategy::orderBuildingKnight()
{
    orderBuildingUnit(knightUnitProperties);
}

bool AIPlayerFastAttackStrategy::isEnemyBaseAttackPossible()
{
    for (const auto& activeKnight: getPlayerActiveUnits().getActiveCombatUnits()) {
        if (!isAttackingUnitPossible(*activeKnight,
                getEnemyActiveUnits().getBase())) {
            return false;
        }
    }

    return true;
}

void AIPlayerFastAttackStrategy::orderEnemyBaseAttack()
{
    for (const auto& activeKnight: getPlayerActiveUnits().getActiveCombatUnits()) {
        orderAttackingUnit(*activeKnight, getEnemyActiveUnits().getBase());
    }
}

std::vector<FieldCoordinates>
AIPlayerFastAttackStrategy::findKnightAttackPositionsToEnemyBase()
{
    std::vector<FieldCoordinates> validAttackPositions;
    FieldCoordinates enemyBasePosition =
            getEnemyActiveUnits().getBase().getCoordinates();
    const GameMap& gameMap = getGameMap();

    for (int y = 0; y<gameMap.getHeight(); ++y) {
        for (int x = 0; x<gameMap.getWidth(); ++x) {
            Knight knight(-1, {x, y});
            FieldCoordinates currentPosition(x, y);

            if (isUnitInAttackRange(knight, enemyBasePosition)
                    && isValidDestinationFieldForMove(currentPosition)) {
                validAttackPositions.push_back(currentPosition);
            }
        }
    }

    return validAttackPositions;
}

void AIPlayerFastAttackStrategy::orderKnightsMoving()
{
    if (getPlayerActiveUnits().getActiveCombatUnits().empty()) {
        return;
    }

    FieldCoordinates knightsPosition = getPlayerActiveUnits().getActiveCombatUnits().at(
            0)->getCoordinates();

    std::vector<FieldCoordinates> validAttackPositions =
            findKnightAttackPositionsToEnemyBase();

    BFSPathfinder pathfinder(getTraversableMap());

    std::vector<FieldCoordinates> shortestPath =
            pathfinder.findShortestPath(knightsPosition, validAttackPositions);

    for (const auto& knightUnit: getPlayerActiveUnits().getActiveCombatUnits()) {
        FieldCoordinates maxTravelDistanceField = findMaxTravelDistanceField(
                shortestPath, knightUnit->getCoordinates(),
                knightUnit->getActionPoints());

        if (maxTravelDistanceField.getX()!=knightUnit->getCoordinates().getX()
                && maxTravelDistanceField.getY()
                        !=knightUnit->getCoordinates().getY()) {
            orderMovingUnit(*knightUnit, maxTravelDistanceField);
        }
    }
}