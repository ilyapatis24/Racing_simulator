#pragma once
#include "Vehicle.h"

class VehicleAssignment
{
	friend class Race;
public:
	Vehicle* const getVehicle() const;
	bool getAssigned() const;
	bool getAvailableToAssign() const;
protected:
	VehicleAssignment(Vehicle* vehicle, bool assigned, bool availableToAssign);
	Vehicle* _vehicle;
	bool _assigned;
	bool _availableToAssign;
};
