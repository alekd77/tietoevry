#ifndef TIETOEVRY_BFSPATHFINDER_H
#define TIETOEVRY_BFSPATHFINDER_H

#include <vector>
#include "../../map/FieldCoordinates.h"

class BFSPathfinder {
public:
    BFSPathfinder(const std::vector<std::vector<bool>>& grid);

    std::vector<FieldCoordinates>
    findShortestPath(const FieldCoordinates& start,
            const std::vector<FieldCoordinates>& end);

    std::vector<FieldCoordinates>
    findShortestPath(const FieldCoordinates& start,
            const FieldCoordinates& end);

private:
    std::vector<std::vector<bool>> pathGrid;    // true = available field, false = obstacle
    int gridWidth;
    int gridHeight;

    bool isValid(int x, int y) const;

    std::vector<FieldCoordinates>
    reconstructPath(const std::vector<std::vector<FieldCoordinates>>& parent,
            const FieldCoordinates& start, const FieldCoordinates& end);
};

#endif //TIETOEVRY_BFSPATHFINDER_H
