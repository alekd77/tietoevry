#ifndef TIETOEVRY_GAMEMAP_H
#define TIETOEVRY_GAMEMAP_H

#include "../util/fileparser/MapDataFileParser.h"
#include <string>
#include <vector>

class GameMap {
public:
    explicit GameMap(const std::string& mapDataFile);

    const std::vector<std::vector<Field>>& getGrid() const;

    const Field& getField(const FieldCoordinates& coordinates) const;

    int getHeight() const;

    int getWidth() const;

    void debugDisplay();

private:
    MapDataFileParser mapDataFileParser;
    std::vector<std::vector<Field>> grid;
    int height;
    int width;
};

#endif // TIETOEVRY_GAMEMAP_H
