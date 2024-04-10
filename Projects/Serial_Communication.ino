void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  if(Serial.available()> 0)
  {
     char state = Serial.read();
     if(state == '1')
     {
       digitalWrite(13,HIGH);
  	   Serial.println("LED ON");
     }
     else if(state == '0')
     {
       digitalWrite(13,LOW);
       Serial.println("LED OFF");
     }
   }
   delay(100);
}
