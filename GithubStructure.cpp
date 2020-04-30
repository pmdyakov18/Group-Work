#include <iostream>
#include <string>


using namespace std;

bool option1Check = false;

struct CARS
{
	string carModel;
	int yearOfCreation;
	string manufacturer;
	int carPrice;
	int ID;
};

void insertCar(CARS car[], int& carCount)
{

	cout << "\nEnter Car Model: ";
	cin >> car[carCount].carModel;

	cout << "\nEnter yearOfCreation: ";
	cin >> car[carCount].yearOfCreation;

	cout << "\nEnter manufacturer: ";
	cin >> (car[carCount].manufacturer);

	cout << "\nEnter Car Price: ";
	cin >> car[carCount].carPrice;


	cout << "\nEnter Car ID: ";
	cin >> car[carCount].ID;



	carCount++;

}


void showCars(CARS car)
{
	cout << "\nManufacturer: " << car.manufacturer << endl;
	cout << "Model: " << car.carModel << endl;
	cout << "Price: " << car.carPrice << endl;
	cout << "Year of creation: " << car.yearOfCreation << endl;
	cout << endl;

}
void showCarsManager(CARS car)
{
	cout << "\nID: " << car.ID << endl;
	cout << "Manufacturer: " << car.manufacturer << endl;
	cout << "Model: " << car.carModel << endl;
	cout << "Price: " << car.carPrice << endl;
	cout << "Year of creation: " << car.yearOfCreation << endl;
	cout << endl;

}
void showAllCars(CARS car[], int carCount)
{

	cout << "\nYou have entered the following cars:" << endl;

	for (int i = 0; i < carCount; i++)
	{
		showCars(car[i]);
	}
}
void showAllCarsManager(CARS car[], int carCount)
{

	cout << "\nYou have entered the following cars:" << endl;

	for (int i = 0; i < carCount; i++)
	{
		showCarsManager(car[i]);
	}
}
void deleteCar(CARS car[], int& carCount)
{
	string carModel;
	int yearOfCreation;
	string manufacturer;
	int carPrice;

	cout << "\nEnter Car Model: ";
	cin >> carModel;

	cout << "Enter price: ";
	cin >> yearOfCreation;

	cout << "Enter manufacturer: ";
	cin >> manufacturer;

	cout << "Enter Car Price: ";
	cin >> carPrice;

	for (int i = 0; i < carCount; i++) {

		if (car[i].manufacturer == manufacturer && car[i].carModel == carModel && car[i].carPrice == carPrice && car[i].yearOfCreation == yearOfCreation) {

			for (int i = 0; i < carCount; i++) {
				car[i] = car[i + 1];
			}

		}

		carCount--;
	}

}

void deleteCarMenu(CARS car[], int& carCount)
{
	deleteCar(car, carCount);
}

int carByID(CARS* car, int& carCount)
{

	for (int i = 0; i < carCount; i++)
	{
		cout << "Enter the carID you want to delete: ";
		cin >> car[i].ID;
		if (car[i].ID == car[i].ID)
		{
			return i;
		}
	}
	return -1;
}

void deleteCarID(CARS* car, int& carCount)
{
	int index = carByID(car, carCount);
	for (int i = index; i < carCount; i++)
	{
		car[i] = car[i + 1];
	}
	carCount--;
}

bool showMainMenu(CARS car[], int& carCount) {

	int choice;
	bool quit = false;
	do {
		if (option1Check == false)
		{
			cout << "\nChoose an option from the menu below:" << endl;
			cout << "1. Insert car." << endl;
			cout << "2. Car list. (Do option 1 first!)" << endl;
			cout << "3. Car list(Manager). (Do option 1 first!)" << endl;
			cout << "4. Delete a car (Do option 1 first!)" << endl;
			cout << "5. Delete car by ID (Do option 1 first!)" << endl;
			cout << "9. Exit." << endl;
			cout << "Enter the option, which you want to use: ";
		}
		else if (option1Check == true)
		{
			cout << endl;
			cout << "\nChoose an option from the menu below:" << endl;
			cout << "1. Insert car." << endl;
			cout << "2. Car list." << endl;
			cout << "3. Car list(Manager)." << endl;
			cout << "4. Delete a car." << endl;
			cout << "5. Delete car by ID." << endl;
			cout << "9. Exit." << endl;
			cout << "Enter the option, which you want to use: ";
		}
		cin >> choice;

			switch (choice)
			{
			case 1:
				insertCar(car, carCount);
				option1Check = true;
				break;
			case 2:
				if (option1Check == false)
				{
					cout << "Do option 1 first!" << endl;
					break;
				}
				else if (option1Check == true)
				{
					showAllCars(car, carCount);
					break;
				}
			case 3:
				if (option1Check == false)
				{
					cout << "Do option 1 first!" << endl;
					break;
				}
				else if (option1Check == true)
				{
					showAllCarsManager(car, carCount);
					break;
				}
			case 4:

				if (option1Check == false)
				{
					cout << "Do option 1 first!" << endl;
					break;
				}
				else if (option1Check == true)
				{
					deleteCar(car, carCount);
					break;
				}
			case 5:
				if (option1Check == false)
				{
					cout << "Do option 1 first!" << endl;
					break;
				}
				else if (option1Check == true)
				{
					deleteCarID(car, carCount);
					break;
				}
			case 9:
				return false;
			}

		} while (quit == false);

	return true;
}

int main()
{
	int carCount = 0;

	CARS car[10];

	bool doShowMenu = true;

	do {
		doShowMenu = showMainMenu(car, carCount);
	} while (doShowMenu);

}
