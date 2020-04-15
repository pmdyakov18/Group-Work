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




int main()
{
	int carCount = 0;

	CARS car[10];


	bool doShowMenu = true;

	do {
		doShowMenu = showMainMenu(car, carCount);
	} while (doShowMenu);
}