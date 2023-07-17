cmake_minimum_required(VERSION 3.19)
project(tietoevry)

# Set the C and C++ compilers
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_STANDARD 17)

add_executable(tietoevry
        src/main.cpp
        src/map/FieldCoordinates.cpp
        src/map/Field.cpp
        src/map/GameMap.cpp
        src/status/GameStatus.cpp
        src/unit/Unit.cpp
        src/unit/combat/CombatUnit.cpp
        src/unit/combat/impl/Knight.cpp
        src/unit/combat/impl/Swordsman.cpp
        src/unit/combat/impl/Archer.cpp
        src/unit/combat/impl/Pikeman.cpp
        src/unit/combat/impl/Catapult.cpp
        src/unit/combat/impl/Ram.cpp
        src/unit/combat/impl/Worker.cpp
        src/unit/builder/BuilderUnit.cpp
        src/unit/builder/impl/Base.cpp
        src/player/Player.cpp
        src/status/ActiveUnits.cpp
        src/util/fileparser/StatusDataFileParser.cpp
        src/util/fileparser/DataFileParser.cpp
        src/player/aiplayer/AIPlayer.cpp
        src/util/fileparser/MapDataFileParser.cpp
        src/command/CommandHandler.cpp
        src/util/pathfinder/BFSPathfinder.cpp
        src/player/aiplayer/impl/AIPlayerFastAttackStrategy.cpp
        )
