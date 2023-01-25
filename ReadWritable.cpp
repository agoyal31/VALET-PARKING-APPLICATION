//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#include "ReadWritable.h"
#include <iostream>
using namespace std;
namespace sdds {

	ReadWritable::ReadWritable()
	{
		flag = false;
	}

	ReadWritable::~ReadWritable()
	{
	}

	bool ReadWritable::isCsv() const
	{
		return flag;
	}
	void ReadWritable::setCsv(bool value)
	{
		flag = value;
	}

	std::ostream& operator<<(std::ostream& coutRef, const ReadWritable& right)
	{
		return right.write(coutRef);
	}

	std::istream& operator>>(std::istream& cinRef, ReadWritable& right)
	{
	    return right.read(cinRef);
	}

}