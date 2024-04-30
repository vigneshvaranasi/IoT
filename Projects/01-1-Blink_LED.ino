int lednum=7;
void setup() {
  pinMode(lednum,OUTPUT);
}

void loop() {
  digitalWrite(lednum,HIGH);
  delay(1000);
  digitalWrite(lednum,LOW);
  delay(1000);
}
