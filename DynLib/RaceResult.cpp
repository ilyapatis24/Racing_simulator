#include "RaceResult.h"

RaceResult::RaceResult(Vehicle* vehicle, double raceTimeHr)
{
	_vehicle = vehicle;
	_raceTimeHr = raceTimeHr;
}

Vehicle* const RaceResult::getVehicle() const
{
	return _vehicle;
}

double RaceResult::getRaceTimeHr() const
{
	return _raceTimeHr;
}