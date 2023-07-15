#include "Field.h"

Field::Field(FieldCoordinates fieldCoordinates, char type)
    : fieldCoordinates(fieldCoordinates), type(type) {}

const FieldCoordinates &Field::getCoordinates() const { return fieldCoordinates; }

char Field::getType() const { return type; }
