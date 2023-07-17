#include <queue>
#include <iostream>
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
    int knightAttackRange = Knight(-1, {1, 1}).getRange();

    const GameMap& gameMap = getGameMap();

    for (int y = 0; y<gameMap.getHeight(); ++y) {
        for (int x = 0; x<gameMap.getWidth(); ++x) {
            FieldCoordinates currentPosition(x, y);

            if (isUnitInAttackRange(knightAttackRange, currentPosition,
                    enemyBasePosition)
                    && isValidDestinationFieldForMove(currentPosition)) {
                validAttackPositions.push_back(currentPosition);
            }
        }
    }

    return validAttackPositions;
}

bool AIPlayerFastAttackStrategy::isUnitInAttackRange(int attackRange,
        const FieldCoordinates& attackerPosition,
        const FieldCoordinates& targetPosition)
{
    return attackRange>=std::abs(attackerPosition.getX()-targetPosition.getX())
            +std::abs(attackerPosition.getY()-targetPosition.getY());
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

FieldCoordinates AIPlayerFastAttackStrategy::findMaxTravelDistanceField(
        const std::vector<FieldCoordinates>& path,
        const FieldCoordinates& start, int unitActionPoints)
{
    bool found = false;
    FieldCoordinates maxTravelDistanceField = {-1, -1};

    for (int i = 0; i<path.size(); ++i) {
        int distance = (std::abs(start.getX()-path.at(i).getX())
                +std::abs(start.getY()-path.at(i).getY()));

        if (unitActionPoints>=distance) {
            maxTravelDistanceField = path.at(i);
            found = true;
        } else {
            break;
        }
    }

    return found ? maxTravelDistanceField : start;
}