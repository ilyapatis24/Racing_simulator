// Racing_simulator_couse_project

#include<iostream>
using namespace std;



int main(int argc, char** argv) {
	system("chcp 1251");

	int typeOfRace = 0;
	float raceDistance = 0;

	do
	{
		cout << "Добро пожаловать в гоночный симулятор!" << endl;
		typeOfRace = ChoosingTypeOfRace();

	} while (!endOfGame());
	return 0;
}