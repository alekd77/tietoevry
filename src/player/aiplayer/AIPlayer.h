#ifndef TIETOEVRY_AIPLAYER_H
#define TIETOEVRY_AIPLAYER_H

#include "../Player.h"

class AIPlayer : public Player {
public:
    AIPlayer(const std::string& mapFile, const std::string& statusFile,
            const std::string& commandsFile);

    virtual void gameStrategy() = 0;
};

#endif //TIETOEVRY_AIPLAYER_H
