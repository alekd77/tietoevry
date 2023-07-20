#include "GameStatus.h"

GameStatus::GameStatus(const std::string& statusDataFile)
        :statusDataFileParser(statusDataFile), currentGoldAmount(
        statusDataFileParser.parseCurrentGoldAmount()), playerActiveUnits(
        statusDataFileParser.parsePlayerUnits()), enemyActiveUnits(
        statusDataFileParser.parseEnemyUnits()) { }

long GameStatus::getCurrentGoldAmount() const { return currentGoldAmount; }

ActiveUnits& GameStatus::getPlayerActiveUnits() { return playerActiveUnits; }

ActiveUnits& GameStatus::getEnemyActiveUnits() { return enemyActiveUnits; }
