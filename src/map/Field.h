#ifndef TIETOEVRY_FIELD_H
#define TIETOEVRY_FIELD_H

#include "FieldCoordinates.h"

class Field {
private:
    FieldCoordinates fieldCoordinates;
    char type;

public:
    explicit Field(FieldCoordinates fieldCoordinates, char type);

    const FieldCoordinates& getCoordinates() const;

    char getType() const;
};

#endif // TIETOEVRY_FIELD_H
