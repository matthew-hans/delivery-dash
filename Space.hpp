/************************************************
 *
 * *Author: Matt Hans
 * *Date: 12/1/2018
 * *Description: header file for space class, declares functions for creating a space object, used as base class for other spaces
 * **********************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <cstdlib>
#include "Driver.hpp"

class Space 
{

	private:
		Space *top,
		      *bottom,
		      *right,
	      	      *left;
		
		Driver d;	
			
	protected:
		char spaceRepresentation = ' ';

	public:
		Space();
		virtual ~Space();
		virtual void interact()=0;
		virtual void addDelivery(int){}
		virtual void subtractTime(int){}
		virtual void addPickups(int){}
		virtual void setPickupPackages(){}
		virtual int getDeliveryEffect()=0;
		virtual int getTimeEffect()=0;
		virtual int getPickupPackages()=0;
		virtual Driver getDriver(){ return d; }
		virtual char getRepresentation();
		void setTopSpace(Space*);
		void setBottomSpace(Space*);
		void setRightSpace(Space*);
		void setLeftSpace(Space*);
};
#endif

