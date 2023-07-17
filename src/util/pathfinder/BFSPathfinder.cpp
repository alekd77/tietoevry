#include "BFSPathfinder.h"
#include <queue>
#include <algorithm>

BFSPathfinder::BFSPathfinder(const std::vector<std::vector<bool>>& grid)
        :pathGrid(grid), gridHeight(static_cast<int>(grid.size())),
         gridWidth(static_cast<int>(grid.at(0).size())) { }

std::vector<FieldCoordinates>
BFSPathfinder::findShortestPath(const FieldCoordinates& start,
        const std::vector<FieldCoordinates>& end)
{
    std::queue<FieldCoordinates> q;
    std::vector<std::vector<bool>> visited(gridHeight,
            std::vector<bool>(gridWidth, false));
    std::vector<std::vector<FieldCoordinates>> parent(gridHeight,
            std::vector<FieldCoordinates>(gridWidth, FieldCoordinates(-1, -1)));

    q.push(start);
    visited[start.getY()][start.getX()] = true;

    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        FieldCoordinates current = q.front();
        q.pop();

        for (const FieldCoordinates& endField: end) {
            if (current.getX()==endField.getX()
                    && current.getY()==endField.getY()) {
                return reconstructPath(parent, start, endField);
            }
        }

        for (int i = 0; i<4; ++i) {
            int nextX = current.getX()+dx[i];
            int nextY = current.getY()+dy[i];

            if (isValid(nextX, nextY) && !visited[nextY][nextX]) {
                q.push(FieldCoordinates(nextX, nextY));
                visited[nextY][nextX] = true;
                parent[nextY][nextX] = current;
            }
        }
    }

    return {};
}

std::vector<FieldCoordinates>
BFSPathfinder::findShortestPath(
        const FieldCoordinates& start, const FieldCoordinates& end)
{
    std::vector<FieldCoordinates> singleEnd;
    singleEnd.push_back(end);
    return findShortestPath(start, singleEnd);
}

bool BFSPathfinder::isValid(int x, int y) const
{
    return x>=0 && x<gridWidth && y>=0 && y<gridHeight && pathGrid[y][x];
}

std::vector<FieldCoordinates>
BFSPathfinder::reconstructPath(
        const std::vector<std::vector<FieldCoordinates>>& parent,
        const FieldCoordinates& start, const FieldCoordinates& end)
{
    std::vector<FieldCoordinates> path;
    FieldCoordinates current = end;

    while (!(current.getX()==start.getX() && current.getY()==start.getY())) {
        path.push_back(current);
        current = parent[current.getY()][current.getX()];
    }

    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return path;
}
