//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include "ReadWritable.h"
#include<iostream>

namespace sdds {

    class Vehicle : public ReadWritable 
    {
    private:
        char m_licensePlate[8 + 1]{};
        char* m_makeAndModel{};
        int m_parkngSpotNum{};

    protected:
        Vehicle& setEmpty();
        bool isEmpty()const;
        const char* getLicensePlate()const;
        const char* getMakeModel()const;
        void setMakeModel(const char* newMakeandModel);

    public:
        Vehicle();
        Vehicle(const char* licensePlate, const char* makeAndModel);
        //Dynamic Memory Allocation//
        Vehicle(Vehicle& otherVehicle);
        Vehicle& operator=(Vehicle& otherVehicle);
        ~Vehicle();
        void setParkingSpot(int newParkingSpotVaue);
        bool operator==(const char* licencePlateValueToCompare)const;
        bool operator==(const Vehicle& anotherVehicleToComparePlate)const;
        std::ostream& write(std::ostream& coutRef = std::cout)const;
        std::istream& read(std::istream& cinRef = std::cin);
        virtual std::ostream& writeType(std::ostream& ostr)const = 0;
        int getParkingSpot() const;

    };

}
#endif

