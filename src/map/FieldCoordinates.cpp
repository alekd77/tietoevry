#include "FieldCoordinates.h"

FieldCoordinates::FieldCoordinates()
        :x(0), y(0) { }

FieldCoordinates::FieldCoordinates(int x, int y)
        :x(x), y(y) { }

int FieldCoordinates::getX() const { return x; }

int FieldCoordinates::getY() const { return y; }

std::string FieldCoordinates::getFieldCoordinatesString() const
{
    return "{"+std::to_string(x)+","+std::to_string(y)+"}";
}
