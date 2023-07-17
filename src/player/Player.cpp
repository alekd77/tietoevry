#include "Player.h"

Player::Player(const std::string& mapFile, const std::string& statusFile,
        const std::string& commandsFile)
        :gameMapFile(mapFile), gameMap(nullptr), gameStatus(statusFile),
         commandHandler(commandsFile) { }

Player::~Player()
{
    commandHandler.saveCommandsToFile();
}

const GameMap& Player::getGameMap()
{
    if (!gameMap) {
        initializeGameMap();
    }

    return *gameMap;
}

const ActiveUnits& Player::getPlayerActiveUnits()
{
    return gameStatus.getPlayerActiveUnits();
}

const ActiveUnits& Player::getEnemyActiveUnits()
{
    return gameStatus.getEnemyActiveUnits();
}

std::vector<std::vector<bool>> Player::getTraversableMap()
{
    if (!gameMap) {
        initializeGameMap();
    }

    std::vector<std::vector<bool>> traversableGrid;

    for (int y = 0; y<gameMap->getHeight(); ++y) {
        std::vector<bool> temp;
        for (int x = 0; x<gameMap->getWidth(); ++x) {
            if (!isValidDestinationFieldForMove(FieldCoordinates(x, y))) {
                temp.push_back(false);
            } else {
                temp.push_back(true);
            }
        }

        traversableGrid.push_back(temp);
    }

    return traversableGrid;
}

bool Player::isMovingUnitPossible(const Unit& unit,
        const FieldCoordinates& destinationField)
{
    if (!doesPlayerUnitExist(unit.getID())) {
        return false;
    }

    if (!unit.canMove()) {
        return false;
    }

    if (!isValidDestinationFieldForMove(destinationField)) {
        return false;
    }

    const CombatUnit* combat = dynamic_cast<CombatUnit*>(const_cast<Unit*>(&unit));

    if (combat) {
        if (calculateRequiredActionPointsForMove(unit.getCoordinates(),
                destinationField)>combat->getActionPoints()) {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool Player::isAttackingUnitPossible(const Unit& attacker,
        const Unit& target) const
{
    if (!doesPlayerUnitExist(attacker.getID())) {
        return false;
    }

    if (!doesPlayerUnitExist(target.getID())) {
        return false;
    }

    if (!attacker.canAttack()) {
        return false;
    }

    const CombatUnit* combat = dynamic_cast<CombatUnit*>(const_cast<Unit*>(&attacker));

    if (combat) {
        if (calculateRequiredRangeForAttack(*combat, target.getCoordinates())
                >combat->getRange()) {
            return false;
        }

        if (calculateRequiredActionPointsForAttack()
                >combat->getActionPoints()) {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool Player::isBuildingUnitPossible(const CombatUnit& unitToBuild) const
{
    if (gameStatus.getPlayerActiveUnits().isBaseBuildingUnit()) {
        return false;
    }

    if (gameStatus.getCurrentGoldAmount()<unitToBuild.getCost()) {
        return false;
    }

    return true;
}

void Player::orderMovingUnit(const Unit& unit,
        const FieldCoordinates& destinationField)
{
    if (!isMovingUnitPossible(unit, destinationField)) {
        return;
    }

    commandHandler.orderMoveCommand(unit.getID(), destinationField);
}

void Player::orderAttackingUnit(const Unit& attacker, const Unit& target)
{
    if (!isAttackingUnitPossible(attacker, target)) {
        return;
    }

    commandHandler.orderAttackCommand(attacker.getID(), target.getID());
}

void Player::orderBuildingUnit(const CombatUnit& unit)
{
    if (!isBuildingUnitPossible(unit)) {
        return;
    }

    commandHandler.orderBuildCommand(
            gameStatus.getPlayerActiveUnits().getBase().getID(),
            unit.getType());
}

bool Player::isValidDestinationFieldForMove(const FieldCoordinates& coordinates)
{
    if (!isFieldOnMap(coordinates)) {
        return false;   // Field outside the map
    }

    if (isObstacleOnField(coordinates)) {
        return false;    // obstacle on field
    }

    if (isEnemyUnitOnField(coordinates)) {
        return false; // enemy unit on field
    }

    return true;
}

bool Player::isUnitInAttackRange(const CombatUnit& attacker,
        const FieldCoordinates& targetPosition)
{
    return attacker.getRange()
            >=std::abs(attacker.getCoordinates().getX()-targetPosition.getX())
                    +std::abs(attacker.getCoordinates().getY()
                            -targetPosition.getY());
}

FieldCoordinates Player::findMaxTravelDistanceField(
        const std::vector<FieldCoordinates>& path,
        const FieldCoordinates& start, int unitActionPoints)
{
    bool found = false;
    FieldCoordinates maxTravelDistanceField = {-1, -1};

    for (int i = 0; i<path.size(); ++i) {
        int distance = calculateRequiredActionPointsForMove(start, path.at(i));

        if (unitActionPoints>=distance) {
            maxTravelDistanceField = path.at(i);
            found = true;
        } else {
            break;
        }
    }

    return found ? maxTravelDistanceField : start;
}

bool Player::isFieldOnMap(const FieldCoordinates& field)
{
    if (!gameMap) {
        initializeGameMap();    // Lazy initialization, creates gameMap only if needed
    }

    if (field.getX()<0) {
        return false;
    }

    if (field.getX()>=gameMap->getWidth()) {
        return false;
    }

    if (field.getY()<0) {
        return false;
    }

    if (field.getY()>=gameMap->getHeight()) {
        return false;
    }

    return true;
}

bool Player::isObstacleOnField(const FieldCoordinates& field)
{
    if (!gameMap) {
        initializeGameMap();    // Lazy initialization, creates gameMap only if needed
    }

    return gameMap->getField(field).getType()=='9';
}

bool Player::isEnemyUnitOnField(const FieldCoordinates& field)
{
    if (!gameMap) {
        initializeGameMap();    // Lazy initialization, creates gameMap only if needed
    }

    if (gameMap->getField(field).getType()=='2') {
        return true;    // enemy base on field
    }

    for (const auto& enemyUnit: gameStatus.getEnemyActiveUnits().getActiveCombatUnits()) {
        FieldCoordinates enemyPosition = enemyUnit->getCoordinates();

        if (field.getX()==enemyPosition.getX()
                && field.getY()==enemyPosition.getY()) {
            return true;
        }
    }

    return false;
}

bool Player::doesPlayerUnitExist(int unitID) const
{
    if (gameStatus.getPlayerActiveUnits().getBase().getID()==unitID) {
        return true;
    }

    for (const auto& unit: gameStatus.getPlayerActiveUnits().getActiveCombatUnits()) {
        if (unit->getID()==unitID) {
            return true;
        }
    }

    return false;
}

int Player::calculateRequiredActionPointsForMove(const FieldCoordinates& start,
        const FieldCoordinates& destination) const
{
    return std::abs(start.getX()-destination.getX())
            +std::abs(start.getY()-destination.getY());
}

int Player::calculateRequiredRangeForAttack(const CombatUnit& attacker,
        const FieldCoordinates& target) const
{
    return std::abs(attacker.getRange()-target.getX())
            +std::abs(attacker.getRange()-target.getY());
}

int Player::calculateRequiredActionPointsForAttack() const
{
    return 1;
}

void Player::initializeGameMap()
{
    gameMap = std::make_unique<GameMap>(gameMapFile);
}

