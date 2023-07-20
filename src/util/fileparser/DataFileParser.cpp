#include "DataFileParser.h"
#include <fstream>
#include <stdexcept>

DataFileParser::DataFileParser(const std::string& dataFile)
        :dataFile(dataFile), dataFileLines(std::vector<std::string>()) { }

void DataFileParser::readDataFile()
{
    std::ifstream inputFile(dataFile);

    if (!inputFile.good()) {
        throw std::runtime_error("Failed to open the "+dataFile+" file.\n");
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        dataFileLines.push_back(line);
    }

    inputFile.close();
}
