#include "VehicleAssignment.h"

VehicleAssignment::VehicleAssignment(Vehicle* vehicle, bool assigned, bool availableToAssign)
{
	_vehicle = vehicle;
	_assigned = assigned;
	_availableToAssign = availableToAssign;
}

Vehicle* const VehicleAssignment::getVehicle() const
{
	return _vehicle;
}

bool VehicleAssignment::getAssigned() const
{
	return _assigned;
}

bool VehicleAssignment::getAvailableToAssign() const
{
	return _availableToAssign;
}