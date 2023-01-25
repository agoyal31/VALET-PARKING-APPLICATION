//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#ifndef SDDS_READWRITABLE_H
#define SDDS_READWRITABLE_H
#include<iostream>

namespace sdds {
    class ReadWritable {
        bool flag;
    public:
        ReadWritable();
        virtual ~ReadWritable();
        bool isCsv()const;
        void setCsv(bool value);
        virtual std::ostream& write(std::ostream& coutRef = std::cout)const = 0;
        virtual std::istream& read(std::istream& cinRef = std::cin) = 0;
    };
    std::ostream& operator<<(std::ostream& coutRef, const ReadWritable& right);
    std::istream& operator>>(std::istream& cinRef, ReadWritable& right);
    
}
#endif 