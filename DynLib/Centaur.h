#pragma once
#include "GroundVehicle.h"

class Centaur : public GroundVehicle
{
public:
    Centaur();

protected:
    virtual double getRestTimeHr(const int distanceKm) const override;
private:
};