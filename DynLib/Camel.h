#pragma once
#include "GroundVehicle.h"

class Camel : public GroundVehicle
{
public:
    Camel();

protected:
    virtual double getRestTimeHr(const int distanceKm) const override;
};