//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include<iostream>

namespace sdds {
    class Car : public Vehicle {
    private:
        bool carwashFlag;
        std::istream& read(std::istream& cinRef = std::cin);
        std::ostream& write(std::ostream& coutRef = std::cout)const;
    public:
        Car();
        Car(const char* licensePlate, const char* makeAndModel);
        Car(Car& secondCar);
        Car& operator=(Car& secondCar);
        ~Car();
        std::ostream& writeType(std::ostream& ostr)const;
        

     };
}
#endif