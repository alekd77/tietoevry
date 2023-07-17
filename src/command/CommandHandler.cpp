#include "CommandHandler.h"

#include <utility>
#include <fstream>

CommandHandler::CommandHandler(std::string commandsFile)
        :commandsFile(std::move(commandsFile))
{
    // Check if the file exists
    if (!doesFileToWriteExist()) {
        throw std::runtime_error(
                "Failed to open the "+this->commandsFile+" file.\n");
    }

    clearCommandsFile();
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

bool CommandHandler::doesFileToWriteExist()
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
