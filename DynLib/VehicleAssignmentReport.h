#pragma once
#include "VehicleAssignment.h"

class VehicleAssignmentReport
{
	friend class Race;
public:
	static const int MIN_VEHICLE_NUMBER = 2;
	~VehicleAssignmentReport();
	VehicleAssignment* const* const getItems() const;
	int getCount() const;
	int getAssignedCount() const;
	bool isReadyToRace() const;
	VehicleAssignment* const operator[](const int i) const;
protected:
	VehicleAssignmentReport(VehicleAssignment** items, int count);
private:
	VehicleAssignment** _items;
	int _count;
	int _assignedCount;
};
