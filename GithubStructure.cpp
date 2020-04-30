// ConsoleApplication25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
bool option1Check = false;
struct CARS {
	int tableNumber = 0;
	string carShow ;
	string manifacturer;
	double total = 0;
	int timeTaken = 0;
	int id = 0;
	int monthlyIncome;
	int yeartOfManidacture;
};
void createCar(CARS* cars, int& carCount, CARS newOrder, int& maxId) {
	newOrder.id = maxId;
	cars[carCount] = newOrder;
	carCount++;
	maxId++;
}
int getCarById(CARS* cars, int& carCount, int id)
{
	for (int i = 0; i < carCount; i++)
	{
		if (cars[i].id == id) 
		{
			return i;
		}
	}

	return -1;
}
void updateCars(CARS* cars, int& carCount, CARS newCar, int& maxId) 
{
	int index = getCarById(cars, carCount, maxId);
	cars[index] = newCar;
}

void deleteCar(CARS* cars, int& carCount, int id) {

	int index = getCarById(cars, carCount, id);
	for (int i = index; i < carCount - 1; i++)
	{
	cars[i] = cars[i + 1];
	}
	carCount--;

}
CARS getOrder(CARS* cars, int& carCount, int id)
{
	int index = getCarById( cars, carCount,  id);
	if (index != id)
	{
		cout << "Enter calid ID";
		cin >> index;
	}
	return cars[index];
}


void showCarMenu(CARS* cars, int& carCount, int& maxId) {

	cout << "\n List of all the cars: " << endl;

	for (int i = 0; i < carCount; i++)
	{
		cout << "\nCar name: " << cars[i].carShow << endl;
		cout << "Manifacturer: " << cars[i].manifacturer << endl;
		cout << "Show tottle time taken: " << cars[i].timeTaken << endl;
		cout <<	"Price: " <<cars[i].total << endl;
		cout << "Yeart of manidacture :" << cars[i].yeartOfManidacture << endl;
	}
}

void CarMenu(CARS* cars, int& carCount, int& maxId) {
	CARS car;

	cout << "Carname name: " ;
	cin >> car.carShow;
	
	cout << "Manifactirer: ";
	cin >> car.manifacturer;
	
	cout << "Yeart of manidacture :";
	while (!(cin >> car.yeartOfManidacture))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct Time: ";
	}

	cout << "Time taken: " ;
	while (!(cin >> car.timeTaken))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct Time: ";
	}


	cout << "Total prize: " ;
	while (!(cin >> car.total
		))
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "\nEnter correct ID: ";
	}

	createCar(cars, carCount, car, maxId);
}
void editOrderMenu(CARS* cars, int& carCount) {
	int carId;
	cout << "\nEnter car id: ";
	cin >> carId;

	CARS car = getOrder(cars, carCount, carId);

	cout << "\n1. Car name: " << endl;
	cout << "2. Manifactirer: " << endl;
	cout << "3. Time taken: " << endl;
	cout << "4. Total prize: " << endl;
	cout << "Yeart of manidacture : "<<endl;
	cout << "Which field do you want to edit: ";

	int edit;
	cin >> edit;

	switch (edit) {
	case 1: {
		cout << "Car namer: ";
		cin >> car.carShow;
		updateCars(cars, carCount, car,  carId);
		break;
	}
	case 2: {
		cout << "Manifactirer:: ";
		cin >> car.manifacturer;
		updateCars(cars, carCount, car, carId);
		break;
	}
	case 3: {
		cout << "Time taken: ";
		cin >> car.timeTaken;
		updateCars(cars, carCount, car, carId);
		break;
	}
	case 4: {
		cout << "Total prize: ";
		cin >> car.total;
		updateCars(cars, carCount, car, carId);
		break;
	}
	case 5: {
		cout << "Yeart of manidacture : ";
		cin >> car.yeartOfManidacture;
		updateCars(cars, carCount, car, carId);
		break;
	}
	default: {
		cout << "Invalid field!" << endl;
		break;
	}


	}
}
void deleteCarMenu(CARS* cars, int& carCount, int& maxId) {
	int carId;

	cout << "Enter car Id: ";
	cin >> carId;

	deleteCar(cars, carCount, carId);
}

bool showMainMenu(CARS* cars, int& carCount, int& maxId) {

	int choice;

	cout << "\n===MAIN MENU===" << endl;
	cout << "1. Car Name" << endl;
	cout << "2. Show Car" << endl;
	cout << "3. Edit Car Order" << endl;
	cout << "4. Delete Car Order" << endl;
	cout << "9. Exit" << endl;
	cout << "Your choice: ";

	cin >> choice;

	switch (choice) {
	case 1: {
		CarMenu(cars, carCount, maxId);
		break;
	}
	case 2: {
		showCarMenu(cars,carCount,maxId);
		break;
	}
	case 3: {
		editOrderMenu(cars, carCount);
		break;
	}	
	case 4: {
		deleteCarMenu(cars, carCount, maxId);
		break;
	}
		 
	case 9: {
		return false;
	}
	default:
		break;

	}
}

int main()
{
	cout << "Car Programe\n";
	int carCount = 0;
	int maxId = 1;
	CARS cars[500];

	bool mainMenu = true;

	do {
		mainMenu = showMainMenu(cars, carCount, maxId);
	} while (mainMenu);
}


