#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);

int potPin = A0;
int ledPin = 9;
int readVal;
int writeVal;

void setup()
{
	Serial.begin(9600);
	pinMode(potPin, INPUT);
	pinMode(ledPin, OUTPUT);
	lcd.init();
	lcd.backlight();
	lcd.begin(16,2);
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print("hello world");
}

void loop()
{	
	lcd.clear();
	readVal = analogRead(potPin);
	writeVal = map(readVal, 0, 1023, 0, 255);
	analogWrite(ledPin, writeVal);
	lcd.print("Brightness: " + String(writeVal/25));
	delay(1000);
}