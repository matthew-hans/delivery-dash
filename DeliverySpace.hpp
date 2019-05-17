/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for traffic space, declares functions for driver options when hitting traffic on route
 * **********************************************/

#ifndef DELIVERYSPACE_HPP
#define DELIVERYSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"

class DeliverySpace : public Space
{
	private:
		char spaceRepresentation = '#';
		int packagesDelivered;
		int pickUpPackages = 0;
		int timeEffect = 1;

	public:
		DeliverySpace();
		~DeliverySpace();
		void interact();
		int getDeliveryEffect();
		int getTimeEffect();
		char getRepresentation();
		bool hasPickup();
		void setPickupPackages();
		int getPickupPackages();
};
#endif
	
