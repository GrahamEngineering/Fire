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
	if (millis() - lastFireTime > _fireInterval)
	{
		lastFireTime = millis();
		return true;
	}
	else
	{
		return false;
	}
}