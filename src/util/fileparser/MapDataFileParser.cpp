#include <sstream>
#include "MapDataFileParser.h"

MapDataFileParser::MapDataFileParser(const std::string& dataFile)
        :DataFileParser(dataFile) {
    readDataFile();

    if (dataFileLines.empty()) {
        throw std::runtime_error("Invalid (empty) " + dataFile + " file content.");
    }
}

std::vector<std::vector<Field>> MapDataFileParser::parseMapGrid()
{
    std::vector<std::vector<Field>> grid;

    int rowIdx = 0;
    for (const std::string& line: dataFileLines) {
        int columnIdx = 0;
        std::vector<Field> gridRow;
        std::istringstream iss(line);
        char fieldType;
        while (iss >> fieldType) {
            Field field = Field({columnIdx, rowIdx}, fieldType);
            gridRow.push_back(field);
            ++columnIdx;
        }

        if (!gridRow.empty()) {
            grid.push_back(gridRow);
        }

        ++rowIdx;
    }

    return grid;
}
