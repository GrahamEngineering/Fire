# Fire

A simple Arduino/ESP8266/NodeMCU timer trigger

## Overview

Fire works as a trigger object with a timeout.  It has to be read using _fire()_ before it will fire again.

## Example

For an example of how to use this, download my SerialUI library and run the included example.

## Fire Library Reference

### Fire::Fire()

Creates a simple Fire object with a default timeout of 1000ms (1 second)

Each object will have the following:
	* bool fire() - returns true if it's time to fire again
	* void setCallback(void (*callback_function) () ) -- Sets a callback function to have happen once the object fires
	* int lastFireTime - tells the millis() value of the previous firing of the object
	
### Fire::Fire(int fireInterval)

Creates a Fire object with a user-specified fire inverval instead of the default 1000ms

_Example:_
```
Fire myFireObject = Fire(2500);		// Creates a trigger that fires every 2.5 seconds
```

### bool Fire::fire()

Checks to see if it's time for the trigger to fire.  Once it returns true, it also updates the lastFireTime and will call a callback function if set

_Example:_
```
void loop()
{
	if (myFireObject.fire())
	{
		// do something
	}
}
```

### void Fire::setCallback(void (*callback_function) () )

Sets a callback function to be triggered once the timer expires

_Example:_
```
Fire myFireObject = Fire(2000);

void setup()
{
	myFireObject.setCallback(cb_function);
}

void loop()
{
	myFireObject.fire();
}

void cb_function()
{
	// do something
}
```

### int Fire::lastFireTime

Shows the millis() value of the last time the object fired.

_Example:_
```
	if (millis() - myFireObject.lastFireTime > 10000)
	{
		myFireObject.fire();
		
	}
```

## Useable Example
```
#include <Fire.h>
/*
	Fire Example
	
	author: matthew.j.graham@gmail.com
	date: 3 Mar 2017

	Note: If uploading to an ESP8266 the logic will be reversed for the LED.
    
		It will stay on and turn off for 100ms ever 2 seconds instead of blinking on for 100ms every 2 seconds.
 
*/
int ledPin = LED_BUILTIN;
Fire blinkStart = Fire(2000);	// start a blink every 2000 ms
Fire blinkEnd = Fire(100);		// end after 100ms

void setup()
{
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void loop()
{
	if (blinkStart.fire())
	{
		// blinkStart has expired, start the led flash
		digitalWrite(ledPin, HIGH);

		// make sure blinkEnd fires to start a new 100ms timer on it.
		blinkEnd.fire();
	}

	// if the light is lit, check the blinkEnd fire object to tell when it's time to turn it off.
	if ( (digitalRead(ledPin) == HIGH) )
	{
		if ( blinkEnd.fire() )
		{
			digitalWrite(ledPin, LOW);
		}
	}
}

```