#include "Arduino.h" // includes the Arduino.h library
int WLED = 9; // led pin - 9
int value = 0; // initial brightness of the led
int changeValue = 5; // how much to change the brightness by every tick
int bar = 0; // initial length of the brightness bar that will be printed in Serial.print
float x = 0; // value multiplier

void setup()
{
	pinMode(WLED, OUTPUT); // sets the led pin to output
	Serial.begin(9600); // sets the data rate to 9600 bits/sec
}

void loop()
{
	
    	for (x=0;x<=6.36;x+=0.1) { // changes multiplier from 0 to 6.36 (2π)
        	value = ((sin(x)+1)*(255/2)); // changes value by multiplier to resemble a sine curve
        	analogWrite(WLED, value); // sets the brightness of the led to value
        	bar = value/10; // sets the length of the bar to value divided by 10
    		// prints the bar
    		for (int i=0; i < bar; i++) {
    			Serial.print("-");
    		}
    		Serial.println(""); // new line
    		delay(30); // delays by 30ms
    	}
}
