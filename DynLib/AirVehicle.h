#pragma once
#include "Vehicle.h"

class AirVehicle : public Vehicle
{
public:
	AirVehicle();
protected:
	double getRaceTimeHr(const int distanceKm) const override;
	virtual double getDistanceReductionPercent(const int distanceKm) const = 0;
};
