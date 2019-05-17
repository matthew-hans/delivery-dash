/************************************************
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for route territory class, declares functions for creation of game "board" or delivery territory
 * **********************************************/

#ifndef TERRITORY_HPP
#define TERRITORY_HPP

#include "Space.hpp"

class Territory
{
	private:
		Space *territory[10][10];
		void createTerritory();
		int numHelpers = 20,
		    numTraffic = 20,
		    numDogs = 10,
		    numPickUps = 5;

		int driverRow,
		    driverCol;
		
	public:	
		Territory();
		~Territory();
		void showTerritory();
		void trackRoute();
		Space* getDriverLoc();
};
#endif

