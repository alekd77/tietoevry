#include "FieldCoordinates.h"

FieldCoordinates::FieldCoordinates(int x, int y)
{
    this->x = x;
    this->y = y;
}

int FieldCoordinates::getX() const { return x; }

int FieldCoordinates::getY() const { return y; }

std::string FieldCoordinates::getFieldCoordinatesString() const
{
    return "{"+std::to_string(x)+","+std::to_string(y)+"}";
}
