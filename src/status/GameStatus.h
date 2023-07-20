#ifndef TIETOEVRY_GAMESTATUS_H
#define TIETOEVRY_GAMESTATUS_H

#include "ActiveUnits.h"
#include "../util/fileparser/StatusDataFileParser.h"
#include <vector>

class GameStatus {
public:
    explicit GameStatus(const std::string& statusDataFile);

    long getCurrentGoldAmount() const;

    ActiveUnits& getPlayerActiveUnits();

    ActiveUnits& getEnemyActiveUnits();

private:
    StatusDataFileParser statusDataFileParser;
    long currentGoldAmount;
    ActiveUnits playerActiveUnits;
    ActiveUnits enemyActiveUnits;
};

#endif // TIETOEVRY_GAMESTATUS_H
