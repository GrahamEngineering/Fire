#include "Arduino.h"
#include "Fire.h"

Fire::Fire()
{
	lastFireTime = millis();
}

Fire::Fire(unsigned long fireInterval)
{
	_fireInterval = fireInterval;
	lastFireTime = millis();
}

bool Fire::fire()
{
	if (millis() - lastFireTime >= _fireInterval)
	{
		if (_isCallbackEnabled)
		{
			_callback();
		}
		
		lastFireTime = millis();

		return true;
	}
	else
	{
		return false;
	}
}

bool Fire::fireExpired()
{
	return (millis() - lastFireTime >= _fireInterval);
}

void Fire::setCallback(void (*callback_function)())
{
	/*
		Set the callback to be triggered later.
	*/
	_callback = callback_function;
	_isCallbackEnabled = true;
}


bool Fire::updateInterval(int newInterval)
{
	_fireInterval = newInterval;
	return true;
}