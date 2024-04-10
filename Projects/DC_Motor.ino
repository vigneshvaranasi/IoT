// DC motor direction and speed control
int in1 = 6;    // Connect IN1 to Arduino pin 6
int in2 = 7;    // Connect IN2 to Arduino pin 7
int enA = 9;    // Connect enA to Arduino pin 9 (PWM capable pin)
int potPin = A0;// Connect potentiometer to Arduino analog pin A0

int Speed = 0;
int val = 0;

void setup() {
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps
  pinMode(enA, OUTPUT); // Configure enA pin as OUTPUT pin
  pinMode(in1, OUTPUT); // Configure IN1 pin as OUTPUT pin
  pinMode(in2, OUTPUT); // Configure IN2 pin as OUTPUT pin
}

void loop() {
  val = analogRead(potPin); // Read potentiometer value to change the motor speed
  Speed = map(val, 0, 1023, 0, 255); // Map potentiometer value to motor speed range (0-255)

  // Anti-clockwise rotation
  if (Serial.available() > 0) {
    char state = Serial.read(); // Reads incoming serial data
    // FORWARD rotation
    if (state == '1') {
      analogWrite(enA, Speed); // Writes PWM value to control motor speed
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      Serial.println("FORWARD"); // Prints data to the serial port
      delay(1000); // waits for 1 second
    }
    // BACKWARD rotation
    else if (state == '0') {
      analogWrite(enA, Speed); // Writes PWM value to control motor speed
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      Serial.println("BACKWARD"); // Prints data to the serial port
      delay(1000); // waits for 1 second
    }
  }
}
