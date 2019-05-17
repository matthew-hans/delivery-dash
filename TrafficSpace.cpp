/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for traffic space, declares functions for driver options when hitting traffic on route
 * **********************************************/

#include "TrafficSpace.hpp"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

TrafficSpace::TrafficSpace()
{

}

TrafficSpace::~TrafficSpace()
{

}

void TrafficSpace::interact()
{
	vector<string> options = {"Take alternate route", "Wait it out", "Take Lunch"};
	Menu trafficMenu(options);

	switch(trafficMenu.showMenu())
	{
	case 1:
					//alternate route options	
		takeAltRoute();
		
		if (0 < timeEffect)
		{
			cout << "Nice job! your alternate route saved you some time" << endl << endl;
		}
		else 
		{
			cout << "Oh no! you've added some time by taking the alternate route" << endl << endl;
		}
	
	case 2:
	
		waitItOut();	//waiting for customor option

		if (timeEffect == -1)
		{
			cout << "Traffic seems to be clearing up pretty quickly!!" << endl << endl;
		}
		else
		{
			cout << "Traffic is very heavy right now" << endl << endl;
		}
	
	case 3:
	
		takeLunch();	//taking a lunch option
				
		if (timeEffect == 0)
		{
			cout << "You decide to pull over and take your lunch" << endl << endl;
		}
	}
}

char TrafficSpace::getRepresentation()
{
	return spaceRepresentation;
}

int TrafficSpace::getTimeEffect()
{
	return timeEffect;
}

int TrafficSpace::getDeliveryEffect()
{
	return 0;
}

void TrafficSpace::takeAltRoute()
{					//randomizes success and returns time of stop depending on outcome
	int successProbability = rand()%100 + 1;
	int comparison = rand()%100 + 1;

	if (comparison <= successProbability)
	{
		timeEffect = 0;
	}
	else 
	{
		timeEffect = 2;
	}
}

void TrafficSpace::waitItOut()
{
	int successProbability = rand()%100 + 1;	//same as above but time risk is higher and so is success probability
	int comparison = rand()%90 + 1;

	if (comparison <= successProbability)
	{
		timeEffect = 0;
	}
	else 
	{
		timeEffect = 3;
	}
}

void TrafficSpace::takeLunch()
{					//time only uses one move for this stop with no deliveries or pickups
	timeEffect = 1;
}
