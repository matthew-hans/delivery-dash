/************************************************
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: main file for delivery dash game, calls proper functions to create game board and allow for gameplay
 * **********************************************/

#include "Territory.hpp"
#include "Menu.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	srand(time(0));

	bool gameOver = false;
	int winningServiceNum = 350;
	int maxMoves = 50;
	int menuChoice;
	Space* driverLocation;
	
	cout << endl << endl << endl;	
	cout << "Welcome to Delivery Dash! A holiday deliver game with added twists" << endl << endl;
	cout << "Here are the basics:" << endl;
	cout << "Delivery dash is a board game where users goal is to collect all 3 of their pickups, service " << winningServiceNum
	     << " packages (pickup packages included) " << endl;
	cout << "and complete these goals all within 50 moves" << endl << endl;
	cout << "Each game board consists of 5 different spaces" << endl;
	cout << "The user can move on to adjacent spaces through the direction menu" << endl << endl;
	cout << "'#' is a standard delivery of 1-3 packages" << endl;
	cout << "'h' is a helper space where users can choose how to best utilize their helper" << endl;
	cout << "'t' is a traffic space where users can decide how the want to handle traffic on route" << endl;
	cout << "'!' is a house with a dog, be careful what you choose to do, it could come back to bite you!" << endl;
	cout << "'D' is a route space that marks the route your driver is taking, no options are given for this spot" << endl << endl;
	cout << "Best of Luck!!" << endl << endl << endl;

	vector<string> options = {"Play game", "Quit"};
	Menu mainMenu(options);
	
	menuChoice = mainMenu.showMenu();
	
	if (menuChoice != 2)
	{
		Territory route;

		while(!gameOver)
		{
			driverLocation = route.getDriverLoc();
			route.showTerritory();	
			cout << endl;
		
			route.trackRoute();
		
			driverLocation = route.getDriverLoc();
	
			cout << "Total Packages Serviced: " << driverLocation->getDriver().getTotalServiced() << endl;
			cout << "Move: " <<  driverLocation->getDriver().getMoves() << " / " << maxMoves << endl;
			cout << "Pickups Made: " << driverLocation->getDriver().getPickupsMade() << " / " << 3 << endl << endl; 
	
			if (maxMoves <= driverLocation->getDriver().getMoves() && driverLocation->getDriver().getTotalServiced() < winningServiceNum)
			{
				cout << "Game Over, you have run out of moves" << endl;
				cout << "You serviced " << driverLocation->getDriver().getTotalServiced() << " packages, the goal is " << winningServiceNum
      				<< " while making all 3 of your pickups" << endl;
				gameOver = true;
			}

			if (driverLocation->getDriver().getMoves() <= maxMoves && winningServiceNum <= driverLocation->getDriver().getTotalServiced()
			    && driverLocation->getDriver().getPickupsMade() == 3)
			{
				cout << "Congradulations!!!" << endl;
				cout << "You serviced " << driverLocation->getDriver().getTotalServiced() << 
				        " packages, the goal is " << winningServiceNum << endl;
				gameOver = true;
			}
		}
		
	}
	system("pause");
	exit(0);
}
