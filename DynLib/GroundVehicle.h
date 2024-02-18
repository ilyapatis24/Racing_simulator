#pragma once
#include "Vehicle.h"

class GroundVehicle : public Vehicle
{
public:
    GroundVehicle();
protected:
    int _motionTimeBeforeRestHr = 0;
    double getRaceTimeHr(const int distanceKm) const override;
    virtual double getMotionTimeHr(const int distanceKm) const;
    virtual double getRestTimeHr(const int distanceKm) const = 0;
    int getRestNumber(const int distanceKm) const;
};
