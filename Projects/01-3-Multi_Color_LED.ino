void setup()
{
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);
  delay(500); 
  digitalWrite(12, LOW);
  delay(200); 
  digitalWrite(4, HIGH);
  delay(500);
  digitalWrite(4, LOW);
  delay(200); 
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(200); 
}