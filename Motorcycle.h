//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/
#ifndef SDDS_MOTORCYCLE_H
#define SDDS_MOTORCYCLE_H

#include "Vehicle.h"
#include<iostream>

namespace sdds {
    class Motorcycle : public Vehicle {

    private:
        bool sidecarFlag;
        std::istream& read(std::istream& cinRef = std::cin);
        std::ostream& write(std::ostream& coutRef = std::cout)const;
    public:
        Motorcycle();
        Motorcycle(const char* licensePlate, const char* makeAndModel);
        Motorcycle(Motorcycle& secondMotorcycle);
        Motorcycle& operator=(Motorcycle& secondMotorcycle);
        ~Motorcycle();
        std::ostream& writeType(std::ostream& ostr)const;
        

    };
}
#endif
