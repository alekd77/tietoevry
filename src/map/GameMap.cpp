#include "GameMap.h"

#include <fstream>
#include <iostream>
#include <sstream>

GameMap::GameMap(const std::string &mapDataFile) {
  initializeGrid(mapDataFile);
  this->height = static_cast<int>(grid.size());
  this->width = static_cast<int>(grid.at(0).size());
}

const std::vector<std::vector<Field>> &GameMap::getGrid() const { return grid; }

int GameMap::getWidth() const { return width; }

int GameMap::getHeight() const { return height; }

void GameMap::debugDisplay() {
  for (const auto &row : grid) {
    for (const auto &field : row) {
      std::cout << field.getType() << " ";
    }
    std::cout << std::endl;
  }
}

void GameMap::initializeGrid(const std::string &mapDataFile) {
  std::ifstream inputFile(mapDataFile);

  if (!inputFile.is_open()) {
    throw std::runtime_error("Failed to open the file.\n");
  }

  int rowIdx = 0;
  std::string line;
  while (std::getline(inputFile, line)) {
    int columnIdx = 0;
    std::vector<Field> gridRow;
    std::istringstream iss(line);
    char fieldType;
    while (iss >> fieldType) {
      Field field = Field({columnIdx, rowIdx}, fieldType);
      gridRow.push_back(field);
      ++columnIdx;
    }

    grid.push_back(gridRow);
    ++rowIdx;
  }

  inputFile.close();
}
