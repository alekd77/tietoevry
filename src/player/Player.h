#ifndef TIETOEVRY_SRC_PLAYER_PLAYER_H_
#define TIETOEVRY_SRC_PLAYER_PLAYER_H_

#include "../status/GameStatus.h"
#include "../command/CommandHandler.h"
#include "../map/GameMap.h"

class Player {
public:
    Player(const std::string& mapFile, const std::string& statusFile,
            const std::string& commandsFile);

    virtual ~Player();

    const GameMap& getGameMap();

    const ActiveUnits& getPlayerActiveUnits();

    const ActiveUnits& getEnemyActiveUnits();

    std::vector<std::vector<bool>> getTraversableMap();

    bool isMovingUnitPossible(const Unit& unit,
            const FieldCoordinates& destinationField);

    bool
    isAttackingUnitPossible(const Unit& attacker, const Unit& target) const;

    bool isBuildingUnitPossible(const CombatUnit& unit) const;

    void
    orderMovingUnit(const Unit& unit, const FieldCoordinates& destinationField);

    void orderAttackingUnit(const Unit& attacker, const Unit& target);

    void orderBuildingUnit(const CombatUnit& unit);

protected:
    bool isValidDestinationFieldForMove(const FieldCoordinates& coordinates);

    bool isUnitInAttackRange(const CombatUnit& attacker,
            const FieldCoordinates& targetPosition);

    FieldCoordinates
    findMaxTravelDistanceField(const std::vector<FieldCoordinates>& path,
            const FieldCoordinates& start, int unitActionPoints);

private:
    std::string gameMapFile;
    std::unique_ptr<GameMap> gameMap;
    GameStatus gameStatus;
    CommandHandler commandHandler;

    bool isFieldOnMap(const FieldCoordinates& field);

    bool isObstacleOnField(const FieldCoordinates& field);

    bool isEnemyUnitOnField(const FieldCoordinates& field);

    bool doesPlayerUnitExist(int unitID) const;

    int calculateRequiredActionPointsForMove(const FieldCoordinates& start,
            const FieldCoordinates& destination) const;

    int calculateRequiredRangeForAttack(const CombatUnit& attacker,
            const FieldCoordinates& target) const;

    int calculateRequiredActionPointsForAttack() const;

    void initializeGameMap();
};

#endif // TIETOEVRY_SRC_PLAYER_PLAYER_H_
