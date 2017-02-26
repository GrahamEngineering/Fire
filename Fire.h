/*
 *  Fire.h
 *
 */
#ifndef Fire_h
#define Fire_h

#include "Arduino.h"

class Fire
{
  public:
    Fire();
	Fire(int);	// Timer with set milliseconds
	bool fire();
	int lastFireTime;
	
  private:
	int _fireInterval = 1000;	// 1 second by default.
	
};


#endif
