/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for delivery dogspace class, declares functions for initializing the interacting with a dog on route
 * **********************************************/

#ifndef DOGSPACE_HPP
#define DOGSPACE_HPP

#include "Space.hpp"
#include "Menu.hpp"

class DogSpace : public Space
{
	private: 
		int packageCount = 0,	
		    timeEffect = 1;
		char spaceRepresentation = '!';
	
	public:
		DogSpace();
		~DogSpace();
		void interact();
		char getRepresentation();
		int getDeliveryEffect();
		int getTimeEffect();
		int getPickupPackages(){ return 0; }
		void attemptDelivery();
		void waitOnOwner();
};
#endif

