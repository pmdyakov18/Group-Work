#include <iostream>
#include <string>

using namespace std;


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
	cin >> car[carCount].manufacturer;

	cout << "\nEnter Car Price: ";
	cin >> car[carCount].carPrice;

  cout<<"Enter Car ID: ";
  cin>>car[carCount].ID;



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

void showAllCars(CARS car[], int carCount)
{

	cout << "\nYou have entered the following cars:" << endl;

	for (int i = 0; i < carCount; i++)
	{
		showCars(car[i]);
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

int main()
{
	int carCount = 0;

	CARS car[10];


	bool doShowMenu = true;

	do {
		doShowMenu = showMainMenu(car, carCount);
	} while (doShowMenu);
}
