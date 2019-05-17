/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for route space, contains driver object which determines win or loss of game
 * **********************************************/

#ifndef ROUTESPACE_HPP
#define ROUTESPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"
#include "Driver.hpp"

class RouteSpace : public Space
{
	private:
		char spaceRepresentation = 'D';
		Driver driver;

	public:
		RouteSpace();
		RouteSpace(Driver);
		~RouteSpace();
		void interact();
		void addDelivery(int);
		void subtractTime(int);
		void addPickups(int);
		char getRepresentation();
		int getDeliveryEffect();
		int getTimeEffect();
		int getPickupPackages(){ return 0; }
		Driver getDriver();
};
#endif
	
