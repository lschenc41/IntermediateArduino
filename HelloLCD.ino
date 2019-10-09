#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
int seconds = 0;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
	lcd.setCursor(0, 0);
  	lcd.print("Hello World");
  	lcd.setCursor(0, 1);
	lcd.print(seconds);
	delay(1000);
	seconds += 1;
	lcd.clear();
}