/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: implementation file for helper class, declares functions and options for utilizing a helper
 * **********************************************/

#include "HelperSpace.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;


HelperSpace::HelperSpace()
{

}

HelperSpace::~HelperSpace()
{

}
					//gives choice on how user wants to utilze helper
void HelperSpace::interact()
{
	vector<string> options = {"Each take a street side", "Deliver large building", "Sort in truck while helper delivers"};
	Menu helperMenu(options);
	int choice = helperMenu.showMenu(); 

	if (choice == 1)
	{
		takeStreetSides();
	}
	if (choice == 2)
	{
		deliverBuilding();
	}
	if (choice == 3)
	{
		sortInTruck();
	}
}

char HelperSpace::getRepresentation()
{
	return spaceRepresentation;
}
					//random delivery, has possiblity to be 4X of any stop
void HelperSpace::takeStreetSides()
{
	deliveryBonus = (rand()%3 + 1) * 4;
	cout << "Nice Job! You and your helper delivered " << deliveryBonus << " packages on this street" << endl << endl;
}
					//random delivery value 2X of any stop and also does not use a move for this space 
void HelperSpace::deliverBuilding()
{
	deliveryBonus = (rand()%3 + 1) * 2;
	timeBonus--;

	cout << "Your helper delivers " << deliveryBonus << " packages in this building" << endl;
	cout << "Move does not count against you for this turn thanks to your helper!!" << endl << endl;
}
					//random delivery possiblity of 3X packages
void HelperSpace::sortInTruck()
{
	deliveryBonus = (rand()%3 + 1) * 3;

	cout << "Your helper delivers " << deliveryBonus << " packages while you sort them in the truck" << endl << endl;
}
			//retursn packages delivered
int HelperSpace::getDeliveryEffect()
{
	return deliveryBonus;
}
			//returns moves used
int HelperSpace::getTimeEffect()
{
	return timeBonus;
}

