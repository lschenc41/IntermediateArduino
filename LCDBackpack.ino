// includes Wire.h, LCD.h, and LiquidCrystal_I2C.h libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7); // sets LiquidCrystal_I2C variable to lcd
const int buttonPin = 2; // button pin - 2
int buttonState = 0; // initial button state (not pressed)
int buttonPresses = 0; // initial # of button presses
int buttonPressed = 0; // tests if the button was pressed on the previous tick

void setup() {
  	Serial.begin(9600); // sets data rate to 9600 bits/sec
  	pinMode(buttonPin, INPUT); // sets the button pin to input
  	lcd.begin (16,2); // starts the lcd with 16 columns and 2 rows
	lcd.setBacklightPin(3,POSITIVE); // sets the lcd backlight pin to 3 and positive
	lcd.setBacklight(HIGH); // turns on backlight
}

void loop() {
	buttonState = digitalRead(buttonPin); // reads the button state
  	lcd.setCursor(0, 0); // sets lcd cursor to first position of first row
  	lcd.print("Button Presses:"); // prints "Button Pressses:" to the first row of the lcd
  	lcd.setCursor(0, 1); // sets cursor to first position of second row
	// if the button wasn't pressed on the previous tick and is currently pressed,
	// increases the number of presses by 1 and sets buttonPressed to 1 for next loop
  	if (buttonPressed == 0 && buttonState == HIGH) {
  		buttonPresses += 1;
  		buttonPressed = 1;
  	}
	// if the button isn't pressed, set buttonPressed to 0 for next loop
  	if (buttonState == LOW) {
  		buttonPressed = 0;
  	}
  	lcd.print(buttonPresses); // prints the number of presses to the second row of the lcd
	delay(30); // delays 30ms
	lcd.clear(); // clears lcd screen to prevent overlap on the next loop
}
