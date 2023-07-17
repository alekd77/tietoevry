#include "GameMap.h"
#include <iostream>

GameMap::GameMap(const std::string& mapDataFile)
        :mapDataFileParser(mapDataFile), grid(mapDataFileParser.parseMapGrid()),
         height(static_cast<int>(grid.size())),
         width(static_cast<int>(grid.at(0).size())) { }

const std::vector<std::vector<Field>>& GameMap::getGrid() const { return grid; }

int GameMap::getHeight() const { return height; }

int GameMap::getWidth() const { return width; }

void GameMap::debugDisplay()
{
    for (const auto& row: grid) {
        for (const auto& field: row) {
            std::cout << field.getType() << " ";
        }
        std::cout << std::endl;
    }
}

const Field& GameMap::getField(const FieldCoordinates& coordinates) const
{
    return grid.at(coordinates.getY()).at(coordinates.getX());
}
