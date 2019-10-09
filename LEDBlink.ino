#include "Arduino.h"
int WLED = 9;
int value = 0;
int changeValue = 5;
int bar = 0;
float x = 0;

void setup()
{
	pinMode(WLED, OUTPUT);
	Serial.begin(9600);
}

void loop()
{
    for (x=0;x<=6.36;x+=0.1) {
        value = ((sin(x)+1)*(255/2));
        analogWrite(WLED, value);
        bar = value/10;
        for (int i=0; i < bar; i++) {
            Serial.print("-");
        }
        Serial.println("");
        delay(30);
    }
}