#include <fstream>
#include <stdexcept>
#include "DataFileParser.h"

DataFileParser::DataFileParser(const std::string& dataFile)
{
    dataFileLines = std::vector<std::string>();
    std::ifstream inputFile(dataFile);

    if (!inputFile.is_open()) {
        throw std::runtime_error("Failed to open the "+dataFile+" file.\n");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        dataFileLines.push_back(line);
    }

    inputFile.close();
}
