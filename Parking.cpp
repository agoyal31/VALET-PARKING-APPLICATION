//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/
#include <iostream>
#include <fstream>
#include "Utils.h"
#include "Parking.h"
#include "Car.h"
#include "Motorcycle.h"

using namespace std;
namespace sdds
{
	Parking::Parking(const char* myFileName, int noOfSpots)
	{
		if (myFileName && myFileName[0]) {
			m_file = new char[ut.strlen(myFileName) + 1];
			ut.strcpy(m_file, myFileName);
		}

		if (noOfSpots > m_maxNumOfParkingSpots || noOfSpots < 10) {
			m_numOfSpots = -1;
		}
		else {
			m_numOfSpots = noOfSpots;
			loadDataFile(); // outside!!!!!!!!!!!!!!!
		}
	}

	bool Parking::isEmpty()
	{
		bool tempFileOpen = true;//creted in parkng.cpp file
		if (m_file)
		{
			tempFileOpen = false;
		}
		else
		{
			tempFileOpen = true;
		}
		return tempFileOpen;
	}

	void Parking::parkingStatus()
	{
		cout << "****** Valet Parking ******" << endl;
		cout << "*****  Available spots: ";
		cout.setf(ios::left);
		cout.width(4);
		cout << m_numOfSpots - m_numOfvehiclesParked;
		cout << " *****" << endl;
	}
	int userSelectedVehicle;

	void Parking::parkVehicle(int userInput)
	{
		bool tocontinue = false;
		//int userSelectedVehicle;//to be connected with submenu
		if (m_numOfSpots - m_numOfvehiclesParked <= 0) {
			cout << "Parking is full";
		}
		else {
			if (userInput == 1) {
				Car* car = new Car;
				car->setCsv(false);
				cin >> *car;
				for (int i = 0; i < m_numOfSpots && tocontinue == false; i++) {
					if (m_Vehiclepointers[i] == nullptr) {
						m_Vehiclepointers[i] = car;
						car->setParkingSpot(i + 1);
						tocontinue = true;
					}
				}

				if (tocontinue == true) {
					cout << endl << "Parking Ticket" << endl;
					cout << *car;
					m_numOfvehiclesParked++;
					cout << endl << "Press <ENTER> to continue....";
					cin.get();
				}
			}
			else if (userInput == 2) {
				Motorcycle* motorcycle = new Motorcycle;
				motorcycle->setCsv(false);
				cin >> *motorcycle;
				for (int i = 0; i < m_numOfSpots; i++) {
					if (m_Vehiclepointers[i] == nullptr) {
						m_Vehiclepointers[i] = motorcycle;
						motorcycle->setParkingSpot(i + 1);
						tocontinue = true;

					}
				}
				if (tocontinue == true) {

					cout << endl << "Parking Ticket" << endl;
					cout << *motorcycle;
					m_numOfvehiclesParked++;
					cout << endl << "Press <ENTER> to continue....";
					cin.get();
				}
			}
		}

		
	}

	void Parking::returnVehcle()
	{
		int found = findVehicle(0);
		if (found >= 0) {
			m_Vehiclepointers[found]->setCsv(false);
			cout << endl << "Returning:" << endl << *m_Vehiclepointers[found];
			m_numOfvehiclesParked--;

			delete m_Vehiclepointers[found];
			m_Vehiclepointers[found] = nullptr;

			cout << endl << "Press <ENTER> to continue....";
			cin.get();
		}

		/*cout << "---------------------------------" << endl;
		cout << "Returning Vehicle" << endl;
		cout << "---------------------------------" << endl<<endl;*/
	}

	void Parking::listParkedVehicles()
	{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < m_numOfSpots; i++) {
			if (m_Vehiclepointers[i] != nullptr) {
				m_Vehiclepointers[i]->setCsv(false);
				cout << *m_Vehiclepointers[i] << "-------------------------------" << endl;
			}
		}
		cout << "Press <ENTER> to continue....";
		cin.ignore(10000, '\n');
		cin.get();
		/*cout << "---------------------------------" << endl;
		cout << "Listing Parked Vehicles" << endl;
		cout << "---------------------------------" << endl<<endl;*/

	}

	int Parking::findVehicle(int flag)
	{
		int vehicleFoundIndex;
		bool vehicleFound = false;
		bool specialCase = false;

		char licencePlateNumber[150];
		if (flag == 1) {
			cout << "Vehicle Search" << endl;
		}
		else {
			cout << "Return Vehicle" << endl;
		}
		cout << "Enter License Plate Number: ";
		cin.ignore(1000, '\n');
		cin.getline(licencePlateNumber, 100, '\n');
		while (ut.strlen(licencePlateNumber) < 1 || ut.strlen(licencePlateNumber) > 8) {
			cout << "Invalid Licence Plate, try again: ";
			for (int i = 0; i < ut.strlen(licencePlateNumber); i++) {
				licencePlateNumber[i] = 0;
			}
			//cin.ignore(1000, '\n');
			cin.getline(licencePlateNumber, 100, '\n');
		}
			for (int i = 0; i < m_numOfvehiclesParked && vehicleFound == false; i++) {
				if (m_Vehiclepointers[i] != nullptr) {
					if (this->m_Vehiclepointers[i]->operator==(licencePlateNumber)) {
						if (flag == 1) {
							cout << endl << "Vehicle found:" << endl;
							m_Vehiclepointers[i]->setCsv(false);
							cout << *m_Vehiclepointers[i];
						}
						vehicleFoundIndex = i;
						vehicleFound = true;

						if (flag == 0 && vehicleFound == true) {
							specialCase = true;
						}

					}

				}
			}
		if (vehicleFound == false) {
			cout << endl << "License plate ";
			for (int i = 0; i < ut.strlen(licencePlateNumber); i++) {
				cout << (char)toupper((char)licencePlateNumber[i]);
			}
			cout << " Not found" << endl;
			vehicleFoundIndex = -1;
		}
		if (specialCase == false) {
			cout << endl << "Press <ENTER> to continue....";
			cin.get();
		}

		return vehicleFoundIndex;
		/*cout << "---------------------------------" << endl;
		cout << "Finding a Vehicle" << endl;
		cout << "---------------------------------" << endl<<endl;*/
	}

	bool Parking::closeParking()
	{
		bool toreturn = false;

		if (m_numOfvehiclesParked == 0) {
			cout << "Closing Parking" << endl;
			toreturn = true;
		}
		else {

			char charEntered;
			bool keepGoing = true;
			//int menuItemSelected = 5;//to be connected with mainMenu


			cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
			cout << "Are you sure? (Y)es/(N)o: ";
			cin >> charEntered;
			if (!(charEntered == 'y' || charEntered == 'y' || charEntered == 'n' || charEntered == 'n'))
			{
				do
				{
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
					cin >> charEntered;
				} while (!(charEntered == 'y' || charEntered == 'y' || charEntered == 'n' || charEntered == 'n'));
			}
			if ((charEntered == 'y' || charEntered == 'y' || charEntered == 'n' || charEntered == 'n') && keepGoing == true)
			{

				if (charEntered == 'y' || charEntered == 'y')
				{
					cout << "Closing Parking" << endl << endl;

					for (int i = 0; i < m_numOfSpots; i++) {
						if (m_Vehiclepointers[i] != nullptr) {
							cout << "Towing request" << endl << "*********************" << endl;
							m_Vehiclepointers[i]->setCsv(false);
							if (i == m_numOfSpots - 1) {
								cout << *m_Vehiclepointers[i];
							}
							else {
								cout << *m_Vehiclepointers[i] << endl;
							}
							delete m_Vehiclepointers[i];
							m_Vehiclepointers[i] = nullptr;
						}
					}
					keepGoing = false;
					toreturn = true;
				}
				else {
					toreturn = false;
				}


			}
		}
		return toreturn;
	}
	

	bool Parking::exitParking()
	{
		//int menuItemSelected = 6;
		char charEntered;


		cout << "This will terminate the program!" << endl;
		cout << "Are you sure? (Y)es/(N)o: ";
		cin >> charEntered;
		if (!(charEntered == 'Y' || charEntered == 'y' || charEntered == 'n' || charEntered == 'N'))
		{
			do
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				cin >> charEntered;
			} while (!(charEntered == 'Y' || charEntered == 'y' || charEntered == 'n' || charEntered == 'N'));
		}

		if (charEntered == 'Y' || charEntered == 'y')
		{
			cout << "Exiting program!" << endl;
		}
		

		return (charEntered == 'Y' || charEntered == 'y');
	}


	bool Parking::loadDataFile()
	{
		char X;
		int parkingSpotCreated;
		bool fileUsedBefore = true;

		if (!isEmpty() && m_numOfSpots > 0) {

			if (m_file && m_file[0]) {

				ifstream openfile(m_file);//read data from file and save it(ifstrem)

				while (!openfile.eof()) {

					openfile.get(X);

					if (X == 'M') {
						Motorcycle* motorcycle = new Motorcycle;
						motorcycle->setCsv(true);
						openfile >> *motorcycle;
						if (!openfile) {
							delete motorcycle;
							fileUsedBefore = false;
						}
						else {
							parkingSpotCreated = motorcycle->getParkingSpot();

							m_Vehiclepointers[parkingSpotCreated - 1] = motorcycle;
						}

					}
					else if (X == 'C') {
						Car* car = new Car;
						car->setCsv(true);
						openfile >> *car;
						if (!openfile) {
							delete car;
							fileUsedBefore = false;
						}
						else {
							parkingSpotCreated = car->getParkingSpot();

							m_Vehiclepointers[parkingSpotCreated - 1] = car;
						}
					}

					if ((X == 'M' || X == 'C') && openfile) {
						m_numOfvehiclesParked = m_numOfvehiclesParked + 1;
						//cin.ignore(10000, '\n');
					}


				}
			}
			else {
				fileUsedBefore = true;
			}
		}
		return fileUsedBefore;
		
	}

	void Parking::saveDataFile()
	{
		ofstream out;
		out.open(m_file);
		if (out) {
			for (int i = 0; i < m_numOfSpots; i++) {
				if (m_Vehiclepointers[i] != nullptr) {
					m_Vehiclepointers[i]->setCsv(true);
					out << *m_Vehiclepointers[i];
				}
			}
		}



		//if (!isEmpty())

		//{
		//	cout << "---------------------------------" << endl;
		//	cout << "Saving data into " << m_file << endl;
		//	cout << "---------------------------------" << endl;
		//};
	}
	Parking::~Parking()
	{
		saveDataFile();
		delete[] m_file;

		for (int i = 0; i <= m_numOfSpots; i++) {
			if (m_Vehiclepointers[i] != nullptr) {
				delete m_Vehiclepointers[i];
			}
		}
	}

	int Parking::run()
	{
		int userResponse = 0;
		int returnedValue;
		bool breakLoop = false;

		if (!isEmpty()) {

			while (userResponse != 5 && breakLoop == false) {

				parkingStatus();

				char indent[4 + 1]{};
				if (MainMenu.returnIndent() == 0) {
					ut.strcpy(indent, "");
				}
				cout << indent << MainMenu.returnm_title() << endl;
				for (int i = 0; i < 6; i++) {
					cout << indent << i + 1 << "- " << MainMenu.returnFirst() << endl;


				}
				MainMenu.countGiven = 0;
				cout << indent << "> ";



				cin >> userResponse;
				if (userResponse == 1)
				{
					if (SubMenu.returnIndent() == 1) {
						ut.strcpy(indent, "    ");
					}
					cout << indent << SubMenu.returnm_title() << endl;
					for (int i = 0; i < 3; i++) {
						cout << indent << i + 1 << "- " << SubMenu.returnSecond() << endl;

					}
					SubMenu.countGiven = 0;

					cout << indent << "> ";
					cin >> userSelectedVehicle;

					if (userSelectedVehicle == 1 || userSelectedVehicle == 2 || userSelectedVehicle == 3)
					{
						parkVehicle(userSelectedVehicle);
					}
				}

				else if (userResponse == 2) {
					returnVehcle();
				}

				else if (userResponse == 3) {
					listParkedVehicles();
				}

				else if (userResponse == 4) {
					findVehicle(1);
				}
				else if (userResponse == 5) {
					closeParking();
				}
				else if (userResponse == 6) 
				{
					if (exitParking()) 
					{
						breakLoop = true;
					};
				}
			}

			if (isEmpty()) {
				returnedValue = 1;
			}
			else {
				returnedValue = 0;
			}

			return returnedValue;
		}
		return 0;
	}
	
}