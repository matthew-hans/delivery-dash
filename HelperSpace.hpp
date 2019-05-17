/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for traffic space, declares functions for driver options when hitting traffic on route
 * **********************************************/

#ifndef HELPERSPACE_HPP
#define HELPERSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"

class HelperSpace : public Space
{
	private: 
		int deliveryBonus = 0;
		int timeBonus = 1;
		char spaceRepresentation = 'h';

	public:
		HelperSpace();
		~HelperSpace();
		void interact();
		char getRepresentation();
		int getDeliveryEffect();
		int getTimeEffect();
		int getPickupPackages(){ return 0; }
		void takeStreetSides();
		void deliverBuilding();
		void sortInTruck(); 
};
#endif

