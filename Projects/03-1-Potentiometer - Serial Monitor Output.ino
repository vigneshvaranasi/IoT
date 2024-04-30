void setup(){
  Serial.begin(9600);
}
void loop(){
  int analogValue = analogRead(A0);
  Serial.print("Analog:");
  Serial.println(analogValue);
  delay(500);
}