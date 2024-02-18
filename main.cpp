#include "StartRacing.h"
#include "AllTerrainBoots.h"
#include "Broomstick.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "FastCamel.h"
#include "FlyingCarpet.h"

int main(int argc, char** argv)
{
	system("chcp 1251");
	Vehicle* vehicles[] = { new AllTerrainBoots(), new Broomstick(), new Camel(), new Centaur(), new Eagle(), new FastCamel(), new FlyingCarpet() };
	int vehicleCount = sizeof(vehicles) / sizeof(Vehicle*);

	try
	{
		StartRacing::greet();
		Race race(vehicles, vehicleCount);
		bool initNewRace = false;

		do
		{
			RaceType raceType = StartRacing::askRaceType();
			int distanceKm = StartRacing::askDistanceKm();
			race.init(raceType, distanceKm);
			StartRacing::clearScreen();
			StartRacing::registerVehicles(race);
			auto raceReport = race.createRaceResultReport();
			StartRacing::showRaceResults(race);
			initNewRace = StartRacing::askNewRaceAction();
			if (initNewRace)
			{
				StartRacing::clearScreen();
			}
		} while (initNewRace);
	}
	catch (std::exception& ex)
	{
		StartRacing::showUnexpectedError(ex);
	}

	for (int i = 0; i < vehicleCount; ++i)
	{
		delete vehicles[i];
	}

	return 0;
}