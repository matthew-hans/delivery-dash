/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: implementation file for space class, defines methods used in creating a space object
 * **********************************************/

#include "Space.hpp"

Space::Space()
{

}

Space::~Space()
{
	
}
					//returns char representing which space is which
char Space::getRepresentation()
{
	return spaceRepresentation;
}
			
void Space::setTopSpace(Space *space)
{
	top = space;
}
							//all functions used for linked together spaces on board
void Space::setBottomSpace(Space *space)
{
	bottom = space;
}

void Space::setRightSpace(Space *space)
{
	right = space;
}
	
void Space::setLeftSpace(Space *space)
{
	left = space;
}

