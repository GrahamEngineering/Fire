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
	void setCallback(void (*callback_function) () );
	bool fire();
	int lastFireTime;
	bool updateInterval(int);
	
  private:
	int _fireInterval = 1000;	// 1 second by default.
	void (*_callback)();
	bool _isCallbackEnabled = false;
};


#endif
