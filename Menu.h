//I have done all the coding by myselfand only copied the code that my professor provided to complete my project milestones.
/*
Name:Avni Goyal
Email:agoyal31@myseneca.ca
Student ID:166795211
Date: 10/12/2022
Section:NBB
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

#include <iostream>

namespace sdds {

	class MenuItems {
		int m_indentation{};
		char m_title[150]{};
		char m_menuTitle[6][40]{};


	public:

		MenuItems(int indent, const char* title);
		int returnIndent();//to access (query) m_indentation
		char* returnm_title();// to access title of main ans sub menu
		char* returnFirst();// to access the options inside the main menu 
		char* returnSecond();// to access the options inside the subMenu

		int countGiven = 0;


	};



}

#endif // !SDDS_MENUITEM_H



