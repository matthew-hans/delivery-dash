/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: implementation file for dogspace class, defines functions for interacting with a dog on route
 * **********************************************/

#include "DogSpace.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

DogSpace::DogSpace()
{
}

DogSpace::~DogSpace()
{
}
				//allows user to decide 3 actions when encountering a dog on route
void DogSpace::interact()
{
	vector<string> options = {"Attempt Delivery (Evasive Manuevers)", "Wait for Owner", "Continue to next stop"};
 	Menu dogMenu(options);
	int choice = dogMenu.showMenu();

	if (choice == 1)
	{
		attemptDelivery();
	}
	if (choice == 2)
	{
		waitOnOwner();
	}
	if (choice == 3)
	{
		timeEffect = 0;		//avoids dog but does not give you any delivery packages
		cout << "You continue to your next stop, move does not count against you" << endl;
	}		

}
					//virtual functions
char DogSpace::getRepresentation()
{
	return spaceRepresentation;
}

int DogSpace::getDeliveryEffect()
{
	return packageCount;
}

int DogSpace::getTimeEffect()
{
	return timeEffect;
}

void DogSpace::attemptDelivery()		//attempts a delivery with completely random success probability, if successful bonus packages 
{						//earned if not loss of packages
	int successProbability = rand()%100 + 1;
	int comparison = rand()%100 + 1;

	if (comparison <= successProbability)	
	{
		packageCount = (rand()%3 + 1) * 4;
	
		cout << "You successfully delivered " << packageCount << " packages while avoiding the dog!!" << endl;
	}
	else
	{
		packageCount = -5;
		timeEffect = timeEffect + 1;
	
		cout << "Ouch!! You were hurt by the dog and lost 5 packages" << endl;
	}
}

void DogSpace::waitOnOwner()
{
						//randomizes packages delivered with success but also increases time of stop (costs you more moves)
	int successProbability = rand()%100 + 1;
	int comparison = rand()%100 + 1;

	if (comparison <= successProbability)	
	{
		packageCount = (rand()%3 + 1) * 2;
		timeEffect++;
	
		cout << "After waiting shortly the owner returns home ," << packageCount << " packages were delivered" << endl;
	}
	else
	{
		packageCount = -5;

		cout << "After waiting shortly the owner is nowhere to be seen" << endl;
		cout << packageCount << " packages subtracted from delivery total" << endl; 
	}
}
