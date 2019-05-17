/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: implementation file for route space, contains driver object which determines win or loss of game
 * **********************************************/

#include "RouteSpace.hpp"
#include <iostream>

using std::cout;
using std::endl;

RouteSpace::RouteSpace()
{

}
					//constructer used for creating routespaces during gameplay, accepts driver object as parameter
RouteSpace::RouteSpace(Driver driver)
{
	this->driver = driver;
}

RouteSpace::~RouteSpace()
{

}

char RouteSpace::getRepresentation()
{
	return spaceRepresentation;
}
				//prints message to indicate user has already been here
void RouteSpace::interact()
{
	cout << "You have already been this way, there are no more deliveries here" << endl << endl;
}

int RouteSpace::getDeliveryEffect()
{
	return 0;
}

int RouteSpace::getTimeEffect()
{
	return 1;
}

void RouteSpace::addPickups(int packages)
{
	driver.addPickupPkgs(packages);
}

void RouteSpace::addDelivery(int packages)
{
	driver.addPackagesDel(packages);
}

void RouteSpace::subtractTime(int time)
{
	driver.incMoves(time);
}
				//getter function used to return the driver object while on route
Driver RouteSpace::getDriver()
{
	return driver;
}
