#include "player/aiplayer/impl/AIPlayerFastAttackStrategy.h"
#include <stdexcept>

int main(int argc, char* argv[])
{
    if (argc<4) {
        throw std::runtime_error("Too few arguments!");
    } else if (argc>5) {
        throw std::runtime_error("Too many arguments!");
    }

    std::string mapFile = argv[1];
    std::string statusFile = argv[2];
    std::string commandsFile = argv[3];
    int timeLimit = 5; // default time limit

    if (argc==5) {
        int definedTimeLimit = std::stoi(argv[4]);
    }

    AIPlayerFastAttackStrategy aiPlayer1(mapFile, statusFile, commandsFile);
    aiPlayer1.gameStrategy();

    return 0;
}
