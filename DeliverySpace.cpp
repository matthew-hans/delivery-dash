/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: implementation file for delivery space class, allows for delivery time and package count to be recorded
 * **********************************************/

#include "DeliverySpace.hpp"
#include <iostream>

using std::cout;
using std::endl;

DeliverySpace::DeliverySpace()
{
}

DeliverySpace::~DeliverySpace()
{
}
				//generates randome delivery number and adds it to packages delivered for this space
void DeliverySpace::interact()
{
	packagesDelivered = rand()%3 + 1;

	cout << "You just delivered " << packagesDelivered << " package at this stop" << endl << endl;
}
					//virtual functions return space variables
char DeliverySpace::getRepresentation()
{
	return spaceRepresentation;
}

int DeliverySpace::getDeliveryEffect()	
{
	return packagesDelivered;
}	

int DeliverySpace::getTimeEffect()
{
	return timeEffect;
}
				//evaluates if a space has a pickup or not (20% have pickups)
bool DeliverySpace::hasPickup()
{
	int randomNum = rand()%100 + 1;

	if (randomNum <= 20)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
				//sets pickup packages for space if it has any
void DeliverySpace::setPickupPackages()
{
	if (hasPickup())
	{
		pickUpPackages = rand()%100 + 50;
		cout << "This stop also has a pickup of " << pickUpPackages << " packages ready for you" << endl;
	}
}
				//returns pickup package count
int DeliverySpace::getPickupPackages()
{
	return pickUpPackages;
}
