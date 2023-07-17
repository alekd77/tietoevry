#ifndef TIETOEVRY_COMMANDHANDLER_H
#define TIETOEVRY_COMMANDHANDLER_H

#include "../map/FieldCoordinates.h"
#include <vector>

class CommandHandler {
public:
    explicit CommandHandler(std::string commandsFile);

    void orderMoveCommand(int unitID, FieldCoordinates destinationField);

    void orderAttackCommand(int attackerID, int targetID);

    void orderBuildCommand(int unitID, char unitType);

    void saveCommandsToFile();

private:
    std::string commandsFile;
    std::vector<std::string> currentCommands;

    bool doesFileToWriteExist();

    void clearCommandsFile();
};

#endif //TIETOEVRY_COMMANDHANDLER_H
