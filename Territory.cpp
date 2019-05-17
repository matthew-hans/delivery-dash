/************************************************
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for route territory class, declares functions for creation of game "board" or delivery territory
 * **********************************************/

#include "Territory.hpp"
#include "DeliverySpace.hpp"
#include "DogSpace.hpp"
#include "TrafficSpace.hpp"
#include "HelperSpace.hpp"
#include "RouteSpace.hpp"
#include <string>
#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Territory::Territory()
{
	createTerritory();
}

Territory::~Territory()
{
	for (int i = 0; i < 10; i++)
	{	for (int j = 0; j < 10; j++)
		{
			delete territory[i][j];
		}
	}

}

void Territory::createTerritory()
{
	int randomRow = 0;
	int randomCol = 0;
							//creates territory in somewhat randomized way, all spaces a originally deliveries
	for (int i = 0; i < 10; i++)			//then it adds in the others but may delete other spaces in the process
	{	for (int j = 0; j < 10; j++)		//this was there is always a slight randomization to each game board in terms of 
		{					//location and number of each space type
			territory[i][j] = new DeliverySpace();
		}
	}

	for (int i = 0; i < numHelpers;)
	{
		randomRow = rand() % 9;
		randomCol = rand() % 9;

		if (territory[randomRow][randomCol]->getRepresentation() == 'h')
		{
			i--;
			continue;
		}
		else 
		{
			delete territory[randomRow][randomCol];
			territory[randomRow][randomCol] = new HelperSpace();
			i++;
		}	
	}

	for (int i = 0; i < numTraffic;)
	{
		randomRow = rand() % 9;
		randomCol = rand() % 9;

		if (territory[randomRow][randomCol]->getRepresentation() == 't')
		{
			i--;
			continue;
		}
		else
		{
			delete territory[randomRow][randomCol];
			territory[randomRow][randomCol] = new TrafficSpace();
			i++;
		}	
	}

	for (int i = 0; i < numDogs;)
	{
		randomRow = rand() % 9;
		randomCol = rand() % 9;

		if (territory[randomRow][randomCol]->getRepresentation() == '!')
		{
			i--;
			continue;
		}
		else
		{
			delete territory[randomRow][randomCol];
			territory[randomRow][randomCol] = new DogSpace();
			i++;
		}	
	}
	driverRow = rand() % 9;
	driverCol = rand() % 9;

	delete territory[driverRow][driverCol];
	territory[driverRow][driverCol] = new RouteSpace();

	for (int i = 0; i < 10; i++)
	{	for (int j = 0; j < 10; j++)
		{						//links all spaces together with pointers to allow for traversing the board 
			if (i == 0)
			{
				territory[i][j]->setTopSpace(NULL);
				territory[i][j]->setBottomSpace(territory[i+1][j]);
			}
			else if (i == 9)
			{
				territory[i][j]->setTopSpace(territory[i-1][j]);
				territory[i][j]->setBottomSpace(NULL);
			}
			else 
			{
				territory[i][j]->setTopSpace(territory[i-1][j]);
				territory[i][j]->setBottomSpace(territory[i+1][j]);
			}

			if (j == 0)		
			{
				territory[i][j]->setLeftSpace(NULL);
				territory[i][j]->setRightSpace(territory[i][j+1]);
			}
			else if (j == 9)
			{
				territory[i][j]->setLeftSpace(territory[i][j-1]);			
				territory[i][j]->setRightSpace(NULL);
			}
			else 
			{
				territory[i][j]->setLeftSpace(territory[i][j-1]);		
				territory[i][j]->setRightSpace(territory[i][j+1]);
			}
		}
	}	
}

void Territory::showTerritory()
{						//displays the board with added spaces for readability
	for (int i = 0; i < 10; i++)
	{	for (int j = 0; j < 10; j++)
		{
			cout << territory[i][j]->getRepresentation() << "  ";
			
			if (j == 9)
			{
				cout << endl << endl;
			}
		}
	} 		
}

void Territory::trackRoute()
{
	vector <string> options = {"Up", "Down", "Right", "Left"};
	Menu directionPad(options);		//options for movement
	
	int PkgPerStop = 0,
	    timePerStop = 0,
	    pickupPkgs = 0;

	Driver temp;


	switch (directionPad.showMenu())
	{
		case 1:
			driverRow--;
							
			if (driverRow < 0)
			{			//used to wrap around board if at end
				driverRow = 9;
			}				
				
			territory[driverRow][driverCol]->interact();
			PkgPerStop = territory[driverRow][driverCol]->getDeliveryEffect();	//gets randomized time and delivery info from stop
			timePerStop = territory[driverRow][driverCol]->getTimeEffect();
		
			if (territory[driverRow][driverCol]->getRepresentation() == '#')
			{	
				territory[driverRow][driverCol]->setPickupPackages();			//determines if there is a pickup or not at a delivery stop
				pickupPkgs = territory[driverRow][driverCol]->getPickupPackages();
			}

			if (driverRow != 9)
			{
				territory[driverRow + 1][driverCol]->addDelivery(PkgPerStop);	//adds moves used as well as pickups to driver object
		
				territory[driverRow + 1][driverCol]->addPickups(pickupPkgs);
				
				territory[driverRow + 1][driverCol]->subtractTime(timePerStop);
		
				temp = territory[driverRow + 1][driverCol]->getDriver();
			}
			else 
			{
				territory[0][driverCol]->addDelivery(PkgPerStop);	//does same but only executes when wrap around occurs
		
				territory[0][driverCol]->addPickups(pickupPkgs);
				
				territory[0][driverCol]->subtractTime(timePerStop);
		
				temp = territory[0][driverCol]->getDriver();
			}

				delete territory[driverRow][driverCol];
				territory[driverRow][driverCol] = new RouteSpace(temp);
			break;
		case 2:
			driverRow++;
											//each case follows same generel format for all 4 directions
			if (9 < driverRow)
			{
				driverRow = 0;
			}
			
		
			territory[driverRow][driverCol]->interact();
			PkgPerStop = territory[driverRow][driverCol]->getDeliveryEffect();
			timePerStop = territory[driverRow][driverCol]->getTimeEffect();

			if (territory[driverRow][driverCol]->getRepresentation() == '#')
			{	
				territory[driverRow][driverCol]->setPickupPackages();
				pickupPkgs = territory[driverRow][driverCol]->getPickupPackages();
			}
			
			if (driverRow != 0)
			{	
				territory[driverRow - 1][driverCol]->addDelivery(PkgPerStop);
		
				territory[driverRow - 1][driverCol]->addPickups(pickupPkgs);
				
				territory[driverRow - 1][driverCol]->subtractTime(timePerStop);
	
				temp = territory[driverRow - 1][driverCol]->getDriver();
			}
			else 
			{
				territory[9][driverCol]->addDelivery(PkgPerStop);
		
				territory[9][driverCol]->addPickups(pickupPkgs);
				
				territory[9][driverCol]->subtractTime(timePerStop);
	
				temp = territory[9][driverCol]->getDriver();
			}

			delete territory[driverRow][driverCol];
			territory[driverRow][driverCol] = new RouteSpace(temp);
					
			break;
		case 3:
	
			driverCol++;
			if(9 < driverCol)
			{
				driverCol = 0;
			}
		
		
			territory[driverRow][driverCol]->interact();
			PkgPerStop = territory[driverRow][driverCol]->getDeliveryEffect();
			timePerStop = territory[driverRow][driverCol]->getTimeEffect();
			
			if (territory[driverRow][driverCol]->getRepresentation() == '#')
			{	
				territory[driverRow][driverCol]->setPickupPackages();
				pickupPkgs = territory[driverRow][driverCol]->getPickupPackages();
			}
	
			if (driverCol != 0)
			{
				territory[driverRow][driverCol - 1]->addDelivery(PkgPerStop);
		
				territory[driverRow][driverCol - 1]->addPickups(pickupPkgs);
				
				territory[driverRow][driverCol - 1]->subtractTime(timePerStop);
	
				temp = territory[driverRow][driverCol - 1]->getDriver();
			}
			else 
			{
				territory[driverRow][9]->addDelivery(PkgPerStop);
		
				territory[driverRow][9]->addPickups(pickupPkgs);
				
				territory[driverRow][9]->subtractTime(timePerStop);
	
				temp = territory[driverRow][9]->getDriver();
			}				

			delete territory[driverRow][driverCol];
			territory[driverRow][driverCol] = new RouteSpace(temp);
			
			break;				
		case 4:
			driverCol--;
			if (driverCol < 0)
			{
				driverCol = 9;
			}
			
			
			territory[driverRow][driverCol]->interact();
			PkgPerStop = territory[driverRow][driverCol]->getDeliveryEffect();
			timePerStop = territory[driverRow][driverCol]->getTimeEffect();

			if (territory[driverRow][driverCol]->getRepresentation() == '#')
			{	
				territory[driverRow][driverCol]->setPickupPackages();
				pickupPkgs = territory[driverRow][driverCol]->getPickupPackages();
			}

			if (driverCol != 9)
			{
				territory[driverRow][driverCol + 1]->addDelivery(PkgPerStop);
		
				territory[driverRow][driverCol + 1]->addPickups(pickupPkgs);
				
				territory[driverRow][driverCol + 1]->subtractTime(timePerStop);
	
				temp = territory[driverRow][driverCol + 1]->getDriver();
			}
			else 
			{
				territory[driverRow][9]->addDelivery(PkgPerStop);
		
				territory[driverRow][9]->addPickups(pickupPkgs);
				
				territory[driverRow][9]->subtractTime(timePerStop);
	
				temp = territory[driverRow][9]->getDriver();
			}	
			delete territory[driverRow][driverCol];
			territory[driverRow][driverCol] = new RouteSpace(temp);
			
	}		
}				

Space* Territory::getDriverLoc()	//returns the location of the driver
{
	Space *driverLocation = territory[driverRow][driverCol];

	return driverLocation;
}



