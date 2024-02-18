#pragma once
#include "AirVehicle.h"

class Broomstick : public AirVehicle
{
public:
	Broomstick();
protected:
	double getDistanceReductionPercent(const int distanceKm) const override;
};
