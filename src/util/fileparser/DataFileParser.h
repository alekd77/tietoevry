#ifndef TIETOEVRY_DATAFILEPARSER_H
#define TIETOEVRY_DATAFILEPARSER_H

#include <vector>
#include <string>

class DataFileParser {
public:
    explicit DataFileParser(const std::string& dataFile);

protected:
    std::string dataFile;
    std::vector<std::string> dataFileLines;

    void readDataFile();
};

#endif //TIETOEVRY_DATAFILEPARSER_H
