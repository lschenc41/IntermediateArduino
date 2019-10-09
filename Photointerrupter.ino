//Photointerrupter.ino

int photoPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(photoPin, INPUT_PULLUP);
}

void loop() {
    attachInterrupt(0, write(), FALLING);
}

void write() {
	digitalWrite(photoPin, HIGH);
}