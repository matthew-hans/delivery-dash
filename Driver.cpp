/************************************************
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: driver class, functions as the player object in the game and contains variables that deterimine a win or loss within the game
 * **********************************************/

#include "Driver.hpp"
#include <iostream>

using std::cout;
using std::endl;

Driver::Driver()
{

}

Driver::~Driver()
{

}
						//adds packages to delivery count
void Driver::addPackagesDel(int packages)
{
	packagesDelivered += packages;	
}

void Driver::addPickupPkgs(int pickupPkgs)
{
	if (pickUps[0] == 0)
	{
		pickUps[0] = pickupPkgs;
	}
	else if (pickUps[1] == 0)
	{
		pickUps[1] = pickupPkgs;
	}
	else if (pickUps[2] == 0)
	{
		pickUps[2] = pickupPkgs;
	}
	else 
	{
		cout << "There is no more room for pickups on your truck!" << endl;
	}	
}
					//increases the moves used by the driver
void Driver::incMoves(int gameMoves)
{
	moves = moves + gameMoves;
}	
				//totals up all serviced packages including pick ups
int Driver::getTotalServiced()
{
	int pickUpTotal = pickUps[0] + pickUps[1] + pickUps[2];

	totalPkgsServiced = packagesDelivered + pickUpTotal;
	
	return totalPkgsServiced;
}

int Driver::getMoves()	//returns the moves used by driver
{
	return moves;
}
				//determines number of pickups made by driver
int Driver::getPickupsMade()
{
	int pickupCounter = 0;

	for (int i = 0; i < 3; i++)
	{
		if (pickUps[i] != 0)
		{
			pickupCounter++;
		}
	}
	return pickupCounter;
}
