int trigPin = 9;    // trig pin of HC-SR04
int echoPin = 8;    // Echo pin of HC-SR04
int revleft = 10;   // REVerse motion of Left motor
int fwdleft = 11;   // ForWarD motion of Left motor
int revright = 12;  // REVerse motion of Right motor
int fwdright = 13;  // ForWarD motion of Right motor

long duration, distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(revleft, OUTPUT);
  pinMode(fwdleft, OUTPUT);
  pinMode(revright, OUTPUT);
  pinMode(fwdright, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  
  if (distance > 19) {
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, HIGH);
    digitalWrite(revleft, LOW);
  } else if (distance < 18) {
    digitalWrite(fwdright, LOW);
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    delay(500);
    
    digitalWrite(fwdright, LOW);
    digitalWrite(revright, HIGH);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, HIGH);
    delay(500);
    
    digitalWrite(fwdright, LOW);
    digitalWrite(revright, LOW);
    digitalWrite(fwdleft, LOW);
    digitalWrite(revleft, LOW);
    delay(100);
    
    digitalWrite(fwdright, HIGH);
    digitalWrite(revright, LOW);
    digitalWrite(revleft, LOW);
    digitalWrite(fwdleft, LOW);
    delay(500);
  }
}
