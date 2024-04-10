int led = 13;
int sensor = 12;
int value = HIGH;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = digitalRead(sensor);
  if (value == HIGH) {
    Serial.println("Object detected");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("Object not detected");
    digitalWrite(led, LOW);
  }
}
