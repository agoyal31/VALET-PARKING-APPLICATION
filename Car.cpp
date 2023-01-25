//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#include <iostream>
#include "Utils.h"
#include "Car.h"
using namespace std;
namespace sdds 
{
	Car::Car() :Vehicle()
	{
		
	}

	Car::Car(const char* licensePlate, const char* makeAndModel):Vehicle(licensePlate,makeAndModel)
	{
	}

	Car::Car(Car& secondCar)
	{
		carwashFlag = secondCar.carwashFlag;
		Vehicle::operator=(secondCar);// when we are calling just name will be given not the type!!!!!!!!!!Remember
	}

	Car& Car::operator=(Car& secondCar)
	{
		carwashFlag = secondCar.carwashFlag;
		Vehicle::operator=(secondCar);
		return *this;
	}

	Car::~Car()
	{
	}

	std::ostream& Car::writeType(std::ostream& ostr) const
	{
		if (isCsv()) {
			ostr << "C,";
		}
		else {
			ostr << "Vehicle type: Car\n";
		}
		return ostr;
	}

	std::istream& Car::read(std::istream& cinRef)
	{
		if (isCsv())
		{
			Vehicle::read(cinRef);
			cinRef >> carwashFlag;
			cinRef.ignore(1000, '\n');
		}
		else
		{

			char approval[100];
			cout <<endl<< "Car information entry" << endl;
			Vehicle::read();
			cout << "Carwash while parked? (Y)es/(N)o: ";
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
				carwashFlag = false;
			}
			else {
				carwashFlag = true;
			}

		}
		return cinRef;
	}

	std::ostream& Car::write(std::ostream& coutRef) const
	{
		if (Vehicle::isEmpty()) 
		{
			coutRef << "Invalid Car Object"<<endl;
	   }
		else 
		{
			Vehicle::write(coutRef);
			if (isCsv()) 
			{
				coutRef << carwashFlag << endl;
            }
			else 
			{
				if (carwashFlag == true) 
				{
					coutRef << "With Carwash" <<endl;
				}
				else 
				{
					coutRef << "Without Carwash"<<endl;
				}
			}
		}
		return coutRef;
	}


}