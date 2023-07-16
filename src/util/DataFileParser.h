#ifndef TIETOEVRY_DATAFILEPARSER_H
#define TIETOEVRY_DATAFILEPARSER_H

#include <vector>
#include <string>

class DataFileParser {
public:
    explicit DataFileParser(const std::string& dataFile);

protected:
    std::vector<std::string> dataFileLines;
};

#endif //TIETOEVRY_DATAFILEPARSER_H
