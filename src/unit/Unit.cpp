#include "Unit.h"
#include <iostream>

Unit::Unit(int id, char type, int hp, const FieldCoordinates& coordinates)
        :id(id), type(type), hp(hp), coordinates(coordinates) { }

Unit::~Unit() = default;

int Unit::getID() const { return id; }

char Unit::getType() const { return type; }

int Unit::getHP() const { return hp; }

const FieldCoordinates& Unit::getCoordinates() const { return coordinates; }

bool Unit::isAlive() const { return hp>0; }

void Unit::move(const FieldCoordinates& newCoordinates)
{
    coordinates = newCoordinates;
}

void Unit::receiveDamage(int damage) { hp -= damage; }

void Unit::debugDisplay() const
{
    std::cout << "ID = " << id << "\n"
              << "Type = " << type << "\n"
              << "HP = " << hp << "\n"
              << "Coordinates = " << coordinates.getFieldCoordinatesString()
              << "\n";
}
