#include "StartRacing.h"

void StartRacing::greet()
{
	std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
}

void StartRacing::showInvalidInputMessage()
{
	std::cout << "Введено неверное значение, повторите ввод!" << std::endl;
}

std::string StartRacing::getRaceTypeName(RaceType raceType)
{
	switch (raceType)
	{
	case GROUND_RACE:
		return std::string("Гонка для наземного транспорта");
	case AIR_RACE:
		return std::string("Гонка для воздушного транспорта");
	default:
		return std::string("Гонка для наземного и воздушного транспорта");
	}
}

RaceType StartRacing::askRaceType()
{
	std::cout << GROUND_RACE << ". " << getRaceTypeName(GROUND_RACE) << std::endl;
	std::cout << AIR_RACE << ". " << getRaceTypeName(AIR_RACE) << std::endl;
	std::cout << MIXED_RACE << ". " << getRaceTypeName(MIXED_RACE) << std::endl;
	int input = 0;
	bool isInputValid = false;
	do
	{
		std::cout << "Выберите тип гонки: ";
		std::cin >> input;
		if (input != static_cast<int>(GROUND_RACE) &&
			input != static_cast<int>(AIR_RACE) &&
			input != static_cast<int>(MIXED_RACE))
		{
			isInputValid = true;
			showInvalidInputMessage();
		}
	} while (isInputValid);

	return static_cast<RaceType>(input);
}

int StartRacing::askDistanceKm()
{
	int input = 0;
	do
	{
		std::cout << "Укажите длину дистанции, км (должна быть положительна): ";
		std::cin >> input;
		if (input <= 0)
		{
			input = 0;
			showInvalidInputMessage();
		}
	} while (input == 0);

	return input;
}

void StartRacing::showRaceSummary(Race& race)
{
	std::cout << getRaceTypeName(race.getRaceType()) << ". Расстояние: " << race.getDistanceKm() << " км." << std::endl;
}

void StartRacing::showRegisteredVehicles(VehicleAssignmentReport& assignmentReport)
{
	int assignedCount = assignmentReport.getAssignedCount();
	std::string vnames;

	if (assignedCount < 2)
	{
		std::cout << "Должно быть зарегистрировано хотя бы " << assignmentReport.MIN_VEHICLE_NUMBER << " транспортных средства." << std::endl;
	}

	if (assignedCount > 0)
	{
		std::cout << "Зарегистрированные транспортные средства: ";
		bool hasAssignedShown = false;
		for (int i = 0; i < assignmentReport.getCount(); ++i)
		{
			if (assignmentReport[i]->getAssigned())
			{
				if (hasAssignedShown)
				{
					std::cout << ", ";
				}

				std::cout << assignmentReport[i]->getVehicle()->getName();
				hasAssignedShown = true;
			}
		}

		std::cout << vnames << std::endl;
	}

	for (int i = 0; i < assignmentReport.getCount(); ++i)
	{
		std::cout << (i + 1) << ". " << assignmentReport[i]->getVehicle()->getName() << std::endl;
	}

	if (assignmentReport.isReadyToRace())
	{
		std::cout << "0. Закончить регистрацию" << std::endl;
	}
}

int StartRacing::askRegistrationAction(Race& race)
{
	showRaceSummary(race);
	auto assignmentReport = race.createAssignmentReport();
	showRegisteredVehicles(assignmentReport);
	int input = 0;
	bool isInputValid = false;
	do
	{
		std::cout << "Выберите действие: ";
		std::cin >> input;
		isInputValid = input > 0 && input <= assignmentReport.getCount() || input == 0 && assignmentReport.isReadyToRace();
		if (!isInputValid)
		{
			showInvalidInputMessage();
		}
	} while (!isInputValid);

	return input;
}

void StartRacing::registerVehicles(Race& race)
{
	bool registrationComplete = false;
	do
	{
		int input = StartRacing::askRegistrationAction(race);
		registrationComplete = input == 0;
		if (!registrationComplete)
		{
			StartRacing::assignVehicle(race, input - 1);
		}
	} while (!registrationComplete);
}

void StartRacing::assignVehicle(Race& race, int index)
{
	clearScreen();
	auto assignmentResult = race.assignVehicle(index);
	auto vehicleName = race.getVehicle(index)->getName();
	switch (assignmentResult)
	{
	case ALREADY_ASSIGNED:
		std::cout << "Транспортное средстро '" + vehicleName << "' уже зарегистрировано на гонку." << std::endl;
		break;
	case INCOMPATIBLE_RACE_TYPE:
		std::cout << "Транспортное средстро '" + vehicleName << "' не подходит по типу." << std::endl;
		break;
	default:
		std::cout << "Транспортное средстро '" + vehicleName << "' успешно зарегистрировано!" << std::endl;
	}
}

void StartRacing::showRaceResults(Race& race)
{
	RaceResultReport resultsReport = race.createRaceResultReport();
	std::cout << std::endl;
	std::cout << "Результаты гонки:" << std::endl;
	for (int i = 0; i < resultsReport.getCount(); ++i)
	{
		auto item = resultsReport[i];
		std::cout << (i + 1) << ". " << item->getVehicle()->getName() << " Время: " << item->getRaceTimeHr() << " ч." << std::endl;
	}
}

bool StartRacing::askNewRaceAction()
{
	int input = 0;
	bool isInputValid = false;
	do
	{
		std::cout << std::endl;
		std::cout << "1. Провести еще одну гонку" << std::endl;
		std::cout << "2. Выйти" << std::endl;
		std::cout << "Выберите действие: ";
		std::cin >> input;

		isInputValid = input == 1 || input == 2;
		if (!isInputValid)
		{
			showInvalidInputMessage();
		}
	} while (!isInputValid);

	return input != 2;
}

void StartRacing::clearScreen()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void StartRacing::showUnexpectedError(std::exception ex)
{
	std::cout << "Непредвиденная ошибка в программе: " << ex.what() << std::endl;
	std::cout << "Программа будет завершена" << std::endl;
}