//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/
#include <iostream>
#include"Utils.h"

#include "Motorcycle.h"
using namespace std;
namespace sdds {
	Motorcycle::Motorcycle() :Vehicle()
	{
	}

	Motorcycle::Motorcycle(const char* licensePlate, const char* makeAndModel) :Vehicle(licensePlate, makeAndModel)
	{
	}

	Motorcycle::Motorcycle(Motorcycle& secondMotorcycle)
	{
		sidecarFlag = secondMotorcycle.sidecarFlag;
		Vehicle::operator=(secondMotorcycle);
	}

	Motorcycle& Motorcycle::operator=(Motorcycle& secondMotorcycle)
	{
		sidecarFlag = secondMotorcycle.sidecarFlag;
		Vehicle::operator=(secondMotorcycle);
		return *this;
	}
	Motorcycle::~Motorcycle()
	{

	}
	std::ostream& Motorcycle::writeType(std::ostream& ostr) const
	{
        if (isCsv()) {
			ostr << "M,";
		}
		else {
			ostr << "Vehicle type: Motorcycle\n";
		}
		return ostr;
	}
	std::istream& Motorcycle::read(std::istream& cinRef)
	{
		if (isCsv())
		{
			Vehicle::read(cinRef);
			cinRef >> sidecarFlag;
			cinRef.ignore(1000, '\n');
		}
		else
		{

			char approval[100];
			cout << endl<<"Motorcycle information entry" << endl;
			Vehicle::read();
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
			cinRef.getline(approval, 100, '\n');

			while ((ut.strlen(approval) > 1) || ((ut.strlen(approval) == 1) && (!(approval[0] == 'y' || approval[0] == 'n' || approval[0] == 'Y' || approval[0] == 'N')))) {

				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";

				for (int i = 0; i < ut.strlen(approval); i++)
				{
					approval[i] = 0;
				}

				cinRef.getline(approval, 100, '\n');

			}

			if (approval[0] == 'n' || approval[0] == 'N') {
				sidecarFlag = false;
			}
			else {
				sidecarFlag = true;
			}

		}
		return cinRef;

	}
	std::ostream& Motorcycle::write(std::ostream& coutRef) const
	{
		if (Vehicle::isEmpty())
		{
			coutRef << "Invalid Motorcycle Object"<<endl;
		}
		else
		{
			Vehicle::write(coutRef);
			if (isCsv())
			{
				coutRef << sidecarFlag << endl;
			}
			else
			{
				if (sidecarFlag == true)
				{
					coutRef << "With Sidecar" << endl;
				}
			}
		}
		return coutRef;
    }
}