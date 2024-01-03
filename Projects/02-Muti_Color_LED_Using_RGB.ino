int redLed=11;
int greenLed=10;
int blueLed=9;

void setup() {
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
}

void loop() {
  RGB_color(255,0,0);
  delay(1000);
  RGB_color(0,255,0);
  delay(1000);
  RGB_color(0,0,255);
  delay(1000);
  RGB_color(255,255,255);
  delay(1000);
  RGB_color(255,165,0);
  delay(1000);
  RGB_color(156,34,93);
  delay(1000);
}

void RGB_color(int red,int green,int blue)
{
  analogWrite(redLed,red);
  analogWrite(greenLed,green);
  analogWrite(blueLed,blue);
}