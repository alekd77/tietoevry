#include "Base.h"

Base::Base(int id, const FieldCoordinates& coordinates)
        :BuilderUnit(id, 'B', 200, coordinates, '0', -1) { }

Base::Base(int id, int hp, const FieldCoordinates& coordinates)
        :BuilderUnit(id, 'B', hp, coordinates, '0', -1) { }

Base::Base(int id, int hp, const FieldCoordinates& coordinates,
        char buildingUnit)
        :BuilderUnit(id, 'B', hp, coordinates, buildingUnit, 0) { }

Base::Base(int id, int hp, const FieldCoordinates& coordinates,
        char buildingUnit, int buildRemainingTurns)
        :BuilderUnit(id, 'B', hp, coordinates, buildingUnit,
        buildRemainingTurns) { }
