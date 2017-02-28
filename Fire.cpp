#include "Arduino.h"
#include "Fire.h"

Fire::Fire()
{
	lastFireTime = millis();
}

Fire::Fire(int fireInterval)
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

void Fire::setCallback(void (*callback_function)())
{
	/*
		Set the callback to be triggered later.
	*/
	_callback = callback_function;
	_isCallbackEnabled = true;
}

