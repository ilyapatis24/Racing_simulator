#pragma once
#include "Vehicle.h"

class RaceResult
{
	friend class Race;
public:
	Vehicle* const getVehicle() const;
	double getRaceTimeHr() const;
protected:
	RaceResult(Vehicle* vehicle, double raceTimeHr);
	Vehicle* _vehicle;
	double _raceTimeHr;

};
