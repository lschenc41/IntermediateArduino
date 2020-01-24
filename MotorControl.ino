int analogPin = A0;
int sensorValue = 0;
int outputValue = 0;
int transistorPin = 3;
void setup()
{
	Serial.begin(9600);
	pinMode(transistorPin, OUTPUT);
	pinMode(analogPin, INPUT);
}

void loop()
{
	sensorValue = analogRead(analogPin);
	outputValue = map(sensorValue, 0, 1023, 0, 255);
	analogWrite(transistorPin, outputValue);
	Serial.println(outputValue);
	delay(10);
}
