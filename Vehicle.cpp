//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Vehicle.h"
#include "Utils.h"



using namespace std;

namespace sdds {

	Vehicle::Vehicle()
	{

	}

	Vehicle::Vehicle(const char* licensePlate, const char* makeAndModel)
	{
		if (licensePlate && ut.strlen(licensePlate) >= 1 && ut.strlen(licensePlate) <= 8 && makeAndModel && ut.strlen(makeAndModel) >= 2) {
			ut.strcpy(m_licensePlate, licensePlate);

			m_makeAndModel = new char[ut.strlen(makeAndModel) + 1];
			ut.strcpy(m_makeAndModel, makeAndModel);
			m_parkngSpotNum = 0;
		}
		else {
			setEmpty();
		}
	}

	Vehicle& sdds::Vehicle::setEmpty()
	{
		for (int i = 0; i < ut.strlen(m_licensePlate); i++) {
			m_licensePlate[i] = 0;
		}
		delete[] m_makeAndModel;
		m_makeAndModel = nullptr;

		m_parkngSpotNum = -1;

		return *this;
	}

	bool Vehicle::isEmpty()const
	{
		bool toReturn = true;
		if (m_licensePlate[0] && m_makeAndModel && m_makeAndModel[0] && m_parkngSpotNum >= 0) {
			toReturn = false;
		}
		return toReturn;
	}

	Vehicle::Vehicle(Vehicle& otherVehicle)
	{
		if (&otherVehicle != this) {
			if (otherVehicle.m_licensePlate[0] && otherVehicle.m_makeAndModel && otherVehicle.m_makeAndModel[0] && otherVehicle.m_parkngSpotNum >= 0) {
				bool isCSV;

				isCSV = otherVehicle.isCsv();
				setCsv(isCSV);

				ut.strcpy(m_licensePlate, otherVehicle.m_licensePlate);
				//strcpy(m_makeAndModel, otherVehicle.m_makeAndModel);

				m_makeAndModel = new char[ut.strlen(otherVehicle.m_makeAndModel) + 1];
				ut.strcpy(m_makeAndModel, otherVehicle.m_makeAndModel);

				m_parkngSpotNum = otherVehicle.m_parkngSpotNum;
			}
		}
	}

	Vehicle& Vehicle::operator=(Vehicle& otherVehicle)//already created object is other vehicle
	{
		if (&otherVehicle != this) {
			if (otherVehicle.m_licensePlate[0] && otherVehicle.m_makeAndModel && otherVehicle.m_makeAndModel[0] && otherVehicle.m_parkngSpotNum >= 0) {
				bool isCSV;

				isCSV = otherVehicle.isCsv();
				setCsv(isCSV);


				for (int i = 0; i < ut.strlen(m_licensePlate); i++) {
					m_licensePlate[i] = 0;
				}

				ut.strcpy(m_licensePlate, otherVehicle.m_licensePlate);

				delete[] m_makeAndModel;
				m_makeAndModel = nullptr;

				m_makeAndModel = new char[ut.strlen(otherVehicle.m_makeAndModel) + 1];
				ut.strcpy(m_makeAndModel, otherVehicle.m_makeAndModel);

				m_parkngSpotNum = otherVehicle.m_parkngSpotNum;
			}
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		delete[] m_makeAndModel;
	}

	int Vehicle::getParkingSpot()const
	{
		return m_parkngSpotNum;
	}

	void Vehicle::setParkingSpot(int newParkingSpotVaue)
	{
		if (newParkingSpotVaue >= 0) {
			m_parkngSpotNum = newParkingSpotVaue;
		}
		else {
			setEmpty();
		}
	}

	bool Vehicle::operator==(const char* licencePlateValueToCompare)const
	{
		bool returned = false;
		int i = 0;
		char* originalString{};
	//	char* givenString{};

		if (licencePlateValueToCompare && licencePlateValueToCompare[0]) {

			originalString = new char[ut.strlen(m_licensePlate) + 1];
			//givenString = new char[ut.strlen(licencePlateValueToCompare) + 1];

			while (m_licensePlate[i] != '\0') {
				//givenString[i] = tolower(licencePlateValueToCompare[i]);
				originalString[i] = tolower(m_licensePlate[i]);
				i++;
			}
			//givenString[i] = 0;
			originalString[i] = 0;

			if (ut.strcmp(originalString, licencePlateValueToCompare) == 0) {
				returned = true;
			}

			delete[] originalString;
		//	delete[] givenString;
		}

		return returned;
	}

	bool Vehicle::operator==(const Vehicle& anotherVehicleToComparePlate) const
	{
		bool returned = false;
		int i = 0;
		char* originalString;
		char* givenString;

		if (anotherVehicleToComparePlate.m_licensePlate && anotherVehicleToComparePlate.m_licensePlate[0]) {

			originalString = new char[ut.strlen(anotherVehicleToComparePlate.m_licensePlate) + 1];
			givenString = new char[ut.strlen(anotherVehicleToComparePlate.m_licensePlate) + 1];

			while (anotherVehicleToComparePlate.m_licensePlate[i] != '\0') {
				givenString[i] = tolower(anotherVehicleToComparePlate.m_licensePlate[i]);
				originalString[i] = tolower(m_licensePlate[i]);
				i++;
			}
			givenString[i] = 0;
			originalString[i] = 0;

			if (ut.strcmp(givenString, originalString) == 0) {
				returned = true;
			}

			delete[] originalString;
			delete[] givenString;
		}

		return returned;
	}

	std::ostream& Vehicle::write(std::ostream& coutRef) const
	{
		if (isEmpty()) {
			coutRef << "Invalid Vehicle Object" << endl;
		}
		else {
			writeType(coutRef);

			if (isCsv()) {
				coutRef << m_parkngSpotNum << ',' << m_licensePlate << ',' << m_makeAndModel << ',';
			}
			else {
				coutRef << "Parking Spot Number: ";
				if (getParkingSpot() == 0) {
					coutRef << "N/A" << endl;
				}
				else {
					coutRef << m_parkngSpotNum << endl;
				}

				coutRef << "License Plate: ";
				coutRef << m_licensePlate << endl;

				coutRef << "Make and Model: ";
				coutRef << m_makeAndModel << endl;
			}
		}

		return coutRef;
	}

	std::istream& Vehicle::read(std::istream& cinRef)
	{
		int i = 0;
		char tempLength[60];

		if (isCsv()) {
			cinRef.ignore(1, ',');
			cinRef >> m_parkngSpotNum;
			cinRef.ignore(1000, ',');

			cinRef.getline(m_licensePlate, 8, ',');

			while (m_licensePlate[i] != '\0') {
				m_licensePlate[i] = toupper(m_licensePlate[i]);
				i++;
			}

			cinRef.getline(tempLength, 60, ',');

			if (m_makeAndModel) {
				delete[] m_makeAndModel;
			}

			m_makeAndModel = new char[60 + 1];
			ut.strcpy(m_makeAndModel, tempLength);


			//for (j = 0; tempLength[j] != '\0'; j++) {
			//	count++;
			//}
			//tempLength[j] = 0;

			if (!cinRef) {
				setEmpty();
			}

		}
		else {
			int i = 0;
			char tempStorage[100];
			char tempStorage2[100];

			cout << "Enter License Plate Number: ";

			cinRef >> tempStorage;

			while (ut.strlen(tempStorage) > 8) {
				cout << "Invalid License Plate, try again: ";
				cinRef >> tempStorage;
			}
			ut.strcpy(m_licensePlate, tempStorage);

			while (m_licensePlate[i] != '\0') {
				m_licensePlate[i] = toupper(m_licensePlate[i]);
				i++;
			}

			cout << "Enter Make and Model: ";

			cinRef.ignore(10000, '\n');

			cinRef.getline(tempStorage2, 60, '\n');

			while (ut.strlen(tempStorage2) < 2 || ut.strlen(tempStorage2) > 60) {
				cout << "Invalid Make and model, try again: ";
				cinRef.getline(tempLength, 60, '\n');
			}

			if (m_makeAndModel) {
				delete[] m_makeAndModel;
			}

			m_makeAndModel = new char[60 + 1];

			ut.strcpy(m_makeAndModel, tempStorage2);

			m_parkngSpotNum = 0;

			if (!cinRef) {
				setEmpty();
			}
		}
		return cinRef;
	}

	const char* Vehicle::getLicensePlate() const
	{
		return m_licensePlate; // why constant here??????????????
	}

	const char* Vehicle::getMakeModel() const
	{
		return m_makeAndModel;
	}

	void Vehicle::setMakeModel(const char* newMakeandModel)
	{
		delete[] m_makeAndModel;

		if (newMakeandModel && newMakeandModel[0]) {
			m_makeAndModel = new char[ut.strlen(newMakeandModel) + 1];
			ut.strcpy(m_makeAndModel, newMakeandModel);
		}
		else {
			setEmpty();
		}
	}






}
