int led = 13;
int ir = 12;
int value = HIGH;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = digitalRead(ir);
  if (value == LOW) {
    Serial.println("Object detected");
    digitalWrite(led, HIGH);
  } else {
    Serial.println("Object not detected");
    digitalWrite(led, LOW);
  }
}
