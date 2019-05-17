/************************************************
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: driver class, functions as the player object in the game and contains variables that deterimine a win or loss within the game
 * **********************************************/

#ifndef DRIVER_HPP
#define DRIVER_HPP

class Driver
{
	private:
		int packagesDelivered,
		    pickUps[3] = {0, 0, 0},
		    totalPkgsServiced = 0,
		    moves = 0;
	
		
	public:
		Driver();
		~Driver();
		void addPackagesDel(int);
		void addPickupPkgs(int);
		void incMoves(int);
		int getTotalServiced();
		int getMoves();
		int getPickupsMade();
};
#endif

