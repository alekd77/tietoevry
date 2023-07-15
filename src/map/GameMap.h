#ifndef TIETOEVRY_GAMEMAP_H
#define TIETOEVRY_GAMEMAP_H

#include "Field.h"
#include <string>
#include <vector>

class GameMap {
public:
  explicit GameMap(const std::string &mapDataFile);

  const std::vector<std::vector<Field>> &getGrid() const;
  int getWidth() const;
  int getHeight() const;

  void debugDisplay();

private:
  std::vector<std::vector<Field>> grid;
  int width;
  int height;

  void initializeGrid(const std::string &mapDataFile);
};

#endif // TIETOEVRY_GAMEMAP_H
