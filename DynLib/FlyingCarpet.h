#pragma once
#include "AirVehicle.h"

class FlyingCarpet : public AirVehicle
{
public:
	FlyingCarpet();
protected:
	double getDistanceReductionPercent(const int distanceKm) const override;
};
