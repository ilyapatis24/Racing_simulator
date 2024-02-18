#pragma once
#include "GroundVehicle.h"

class AllTerrainBoots : public GroundVehicle
{
public:
    AllTerrainBoots();

protected:
    virtual double getRestTimeHr(const int distanceKm) const override;
};
