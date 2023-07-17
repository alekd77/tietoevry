#ifndef TIETOEVRY_MAPDATAFILEPARSER_H
#define TIETOEVRY_MAPDATAFILEPARSER_H

#include "DataFileParser.h"
#include "../../map/Field.h"

class MapDataFileParser : public DataFileParser {
public:
    explicit MapDataFileParser(const std::string& dataFile);

    std::vector<std::vector<Field>> parseMapGrid();
};

#endif //TIETOEVRY_MAPDATAFILEPARSER_H
