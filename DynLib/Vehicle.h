#pragma once
#include "VehicleType.h"
#include <string>

class Vehicle
{
public:
    friend class Race;
    virtual ~Vehicle();
    std::string& getName();
    VehicleType getVehicleType();

protected:
    VehicleType _type;
    std::string _name;
    int _velocityKmh;
    virtual double getRaceTimeHr(const int distanceKm) const = 0;
};

