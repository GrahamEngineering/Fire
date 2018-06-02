#include <Fire.h>
/*
	Fire Example
	
	author: matthew.j.graham@gmail.com
	date: 3 Mar 2017
	updated: 2 June 2018

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

