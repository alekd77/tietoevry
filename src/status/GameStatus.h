#ifndef TIETOEVRY_GAMESTATUS_H
#define TIETOEVRY_GAMESTATUS_H

#include "ActiveUnits.h"
#include "../util/StatusDataFileParser.h"
#include <vector>

class GameStatus {
public:
    explicit GameStatus(const std::string& statusDataFile);

    long getCurrentGoldAmount() const;

    const ActiveUnits& getPlayerActiveUnits() const;

    const ActiveUnits& getEnemyActiveUnits() const;

private:
    StatusDataFileParser statusDataFileParser;
    long currentGoldAmount;
    ActiveUnits playerActiveUnits;
    ActiveUnits enemyActiveUnits;
};

#endif // TIETOEVRY_GAMESTATUS_H
