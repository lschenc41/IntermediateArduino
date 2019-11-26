#include <LiquidCrystal.h> // includes LiquidCrystal.h library
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // sets the LiquidCrystal variable to lcd
int seconds = 0; // initial seconds passed since program started

void setup() {
  lcd.begin(16, 2); // starts the lcd with 16 columns and 2 rows
}

void loop() {
	lcd.setCursor(0, 0); // sets lcd cursor to the first position of the first row
  	lcd.print("Hello World"); // prints "Hello World" to the first row of the lcd
  	lcd.setCursor(0, 1); // sets cursor to the first position of the second row
	lcd.print(seconds); // prints the number of seconds
	delay(1000); // delays one second
	seconds += 1; // increases seconds by one
	lcd.clear(); // clears lcd to prevent it from printing over itself on the next loop
}
