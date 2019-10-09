#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7);
const int buttonPin = 2;
int buttonState = 0;
int buttonPresses = 0;
int buttonPressed = 0;

void setup() {
  	Serial.begin(9600);
  	pinMode(buttonPin, INPUT);
  	lcd.begin (16,2);
	lcd.setBacklightPin(3,POSITIVE);
	lcd.setBacklight(HIGH);
}

void loop() {
	buttonState = digitalRead(buttonPin);
  	lcd.setCursor(0, 0);
  	lcd.print("Button Presses:");
  	lcd.setCursor(0, 1);
  	if (buttonPressed == 0 && buttonState == HIGH) {
  		buttonPresses += 1;
  		buttonPressed = 1;
  	}
  	if (buttonState == LOW) {
  		buttonPressed = 0;
  	}
  	lcd.print(buttonPresses);
	delay(30);
	lcd.clear();
}