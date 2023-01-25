//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/
#ifndef _SDDS_PARKING_H
#define _SSDS_PARKING_H
#include <iostream>
#include"Vehicle.h"
#include "Menu.h"
namespace sdds
{
	class Parking
	{
	private:

		const int m_maxNumOfParkingSpots = 100;
		int m_numOfSpots{};//always less than or equal to maximum parking spots
		int m_numOfvehiclesParked{};//always less than number of spots available
		Vehicle* m_Vehiclepointers[100]{};//parking spots int he parking


		char* m_file{};
		Parking(const Parking&) = delete;
		Parking& operator=(const Parking&) = delete;
		bool isEmpty();
		void parkingStatus();
		void parkVehicle(int userInput);
		void returnVehcle();
		void listParkedVehicles();
		int findVehicle(int flag);
		bool closeParking();
		bool exitParking();
		bool loadDataFile();
		void saveDataFile();

		MenuItems MainMenu{ 0, "Parking Menu, select an action:" };// object 
		MenuItems SubMenu{ 1, "Select type of the vehicle:" };
	public:

		
		Parking(const char* myFileName, int noOfSpots);
		int run();
		~Parking();//destructor

	};


}



#endif 

