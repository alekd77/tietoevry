#include "CombatUnit.h"
#include <iostream>

CombatUnit::CombatUnit(int id, char type, int hp,
        const FieldCoordinates& coordinates, int actionPoints, int cost,
        int range, int buildTime)
        :Unit(id, type, hp, coordinates), actionPoints(actionPoints),
         cost(cost), range(range), buildTime(buildTime) { }

int CombatUnit::getActionPoints() const { return actionPoints; }

int CombatUnit::getCost() const { return cost; }

int CombatUnit::getRange() const { return range; }

int CombatUnit::getBuildTime() const { return buildTime; }

bool CombatUnit::canMove() const { return true; }

bool CombatUnit::canAttack() const { return true; }

bool CombatUnit::canBuild() const { return false; }

void CombatUnit::useActionPoints(int usedActionPoints) {
    actionPoints -= usedActionPoints;
}

void CombatUnit::debugDisplay() const
{
    Unit::debugDisplay();
    std::cout << "Action Points = " << actionPoints << "\n"
              << "Cost = " << cost << "\n"
              << "Range = " << range << "\n"
              << "Build time = " << buildTime << "\n";
}