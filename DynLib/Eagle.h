#pragma once
#include "AirVehicle.h"

class Eagle : public AirVehicle
{
public:
	Eagle();
protected:
	double getDistanceReductionPercent(const int distanceKm) const override;
};
