//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/


#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include "Utils.h"

using namespace std;

namespace sdds {

	MenuItems::MenuItems(int indent, const char* title)
	{
		m_indentation = indent;

		if (title && title[0] && m_menuTitle && m_menuTitle[0]) {
			ut.strcpy(m_title, title);
		}

		if (indent == 0) {
			ut.strcpy(m_menuTitle[0], "Park Vehicle");
			ut.strcpy(m_menuTitle[1], "Return Vehicle");
			ut.strcpy(m_menuTitle[2], "List Parked Vehicles");
			ut.strcpy(m_menuTitle[3], "Find Vehicle");
			ut.strcpy(m_menuTitle[4], "Close Parking (End of day)");
			ut.strcpy(m_menuTitle[5], "Exit Program");
		}
		else if (indent == 1) {
			ut.strcpy(m_menuTitle[0], "Car");
			ut.strcpy(m_menuTitle[1], "Motorcycle");
			ut.strcpy(m_menuTitle[2], "Cancel");
			ut.strcpy(m_menuTitle[3], "\0");
		}

	}
	int MenuItems::returnIndent()
	{
		return m_indentation;
	}
	char* MenuItems::returnm_title()
	{
		return m_title;
	}
	char* MenuItems::returnFirst()
	{

		countGiven++;
		return m_menuTitle[countGiven - 1];
	}
	char* MenuItems::returnSecond()
	{
		countGiven++;
		return m_menuTitle[countGiven - 1];
	}
}