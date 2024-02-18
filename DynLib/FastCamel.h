#pragma once
#include "GroundVehicle.h"

class FastCamel : public GroundVehicle
{
public:
    FastCamel();

protected:
    virtual double getRestTimeHr(const int distanceKm) const override;
};