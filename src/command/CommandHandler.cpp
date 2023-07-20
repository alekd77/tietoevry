#include "CommandHandler.h"
#include <fstream>

CommandHandler::CommandHandler(const std::string& commandsFile)
        :commandsFile(commandsFile), currentCommands(std::vector<std::string>())
{
    if (!doesCommandsFileExist()) {
        std::ofstream file(this->commandsFile); // Creates empty file if the given file does not exist
        file.close();
    } else {
        clearCommandsFile();
    }
}

void CommandHandler::orderMoveCommand(int unitID,
        FieldCoordinates destinationField)
{
    std::string command =
            std::to_string(unitID)+" M "+std::to_string(destinationField.getX())
                    +" "+std::to_string(destinationField.getY());

    currentCommands.push_back(command);
}

void CommandHandler::orderAttackCommand(int attackerID, int targetID)
{
    std::string command =
            std::to_string(attackerID)+" A "+std::to_string(targetID);

    currentCommands.push_back(command);
}

void CommandHandler::orderBuildCommand(int unitID, char unitType)
{
    std::string command = std::to_string(unitID)+" B "+unitType;

    currentCommands.push_back(command);
}

void CommandHandler::saveCommandsToFile()
{
    std::ofstream ofs(commandsFile);

    for (const std::string& command: currentCommands) {
        ofs << command << "\n";
    }

    ofs.close();
}

bool CommandHandler::doesCommandsFileExist()
{
    std::ifstream file(commandsFile);
    return file.good();
}

void CommandHandler::clearCommandsFile()
{
    // Clear the file by opening it in truncation mode
    std::ofstream ofs(commandsFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
