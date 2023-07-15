#ifndef TIETOEVRY_UNIT_H
#define TIETOEVRY_UNIT_H

#include "../map/FieldCoordinates.h"

class Unit {
public:
  Unit(int id, char type, int hp, const FieldCoordinates &coordinates);

  virtual ~Unit();

  int getID() const;

  char getType() const;

  int getHP() const;

  const FieldCoordinates &getCoordinates() const;

  bool isAlive() const;

  void receiveDamage(int damage);

  virtual bool canMove() const = 0;

  virtual bool canAttack() const = 0;

  virtual bool canBuild() const = 0;

  virtual void debugDisplay() const;

private:
  int id;
  char type;
  int hp;
  FieldCoordinates coordinates;
};

#endif // TIETOEVRY_UNIT_H
