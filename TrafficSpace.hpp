/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for traffic space, declares functions for driver options when hitting traffic on route
 * **********************************************/

#ifndef TRAFFICSPACE_HPP
#define TRAFFICSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"

class TrafficSpace : public Space
{
	private:
		int timeEffect = 1,
		    lunchesLeft = 1;
		char spaceRepresentation = 't';

	public: 
		TrafficSpace();
		~TrafficSpace();
		void interact();
		char getRepresentation();
		int getTimeEffect();
		int getDeliveryEffect();
		int getPickupPackages(){ return 0; }
		void takeAltRoute();
		void waitItOut();
		void takeLunch();
};
#endif
	
