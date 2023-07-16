#include "GameStatus.h"

GameStatus::GameStatus(const std::string &statusDataFile) : statusDataFileParser(statusDataFile), currentGoldAmount(
        statusDataFileParser.parseCurrentGoldAmount()), playerActiveUnits(
        statusDataFileParser.parsePlayerUnits()), enemyActiveUnits(
        statusDataFileParser.parseEnemyUnits()) {}

long GameStatus::getCurrentGoldAmount() const { return currentGoldAmount; }

const ActiveUnits &GameStatus::getPlayerActiveUnits() const { return playerActiveUnits; }

const ActiveUnits &GameStatus::getEnemyActiveUnits() const { return enemyActiveUnits; }
