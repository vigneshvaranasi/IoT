int enA = 9;    // PWM pin for motor speed control
int in1 = 6;    // Motor input 1
int in2 = 7;    // Motor input 2
int potPin = A0;// Potentiometer pin for speed control

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  int Speed = map(analogRead(potPin), 0, 1023, 0, 255);

  if (Serial.available() > 0) {
    char state = Serial.read();
    if (state == '1') { // Forward rotation
      analogWrite(enA, Speed);
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      Serial.println("FORWARD");
    } 
    else if (state == '0') { // Backward rotation
      analogWrite(enA, Speed);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      Serial.println("BACKWARD");
    }
    delay(1000);
  }
}
