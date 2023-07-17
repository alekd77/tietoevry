#ifndef TIETOEVRY_FIELDCOORDINATES_H
#define TIETOEVRY_FIELDCOORDINATES_H

#include <string>

class FieldCoordinates {
public:
    FieldCoordinates();
    FieldCoordinates(int x, int y);

    int getX() const;

    int getY() const;

    std::string getFieldCoordinatesString() const;

private:
    int x;
    int y;
};

#endif // TIETOEVRY_FIELDCOORDINATES_H
