#ifndef TIETOEVRY_AIPLAYERFASTATTACKSTRATEGY_H
#define TIETOEVRY_AIPLAYERFASTATTACKSTRATEGY_H

#include "../AIPlayer.h"

#include "../../../unit/combat/impl/Knight.h"

class AIPlayerFastAttackStrategy : public AIPlayer {
public:
    AIPlayerFastAttackStrategy(const std::string& mapFile,
            const std::string& statusFile, const std::string& commandsFile);

    void gameStrategy() override;

private:
    Knight knightUnitProperties;

    bool isBuildingKnightPossible() const;

    void orderBuildingKnight();

    bool isEnemyBaseAttackPossible();

    void orderEnemyBaseAttack();

    bool isUnitInAttackRange(int attackRange,
            const FieldCoordinates& attackerPosition,
            const FieldCoordinates& targetPosition);

    void orderKnightsMoving();

    FieldCoordinates
    findMaxTravelDistanceField(const std::vector<FieldCoordinates>& path,
            const FieldCoordinates& start, int unitActionPoints);

    std::vector<FieldCoordinates> findKnightAttackPositionsToEnemyBase();
};

#endif //TIETOEVRY_AIPLAYERFASTATTACKSTRATEGY_H
