int LED_PIN =13; 
int analogValue = 0;
int brightness = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); 
}
void loop() {
  analogValue = analogRead(A0); 
  brightness = map(analogValue,0,1023,0,255);
  analogWrite(LED_PIN, brightness);
  Serial.print("Analog:"); 
  Serial.print(analogValue);
  Serial.print("Brightness:"); 
  Serial.println(brightness);
  delay(1000); 
}