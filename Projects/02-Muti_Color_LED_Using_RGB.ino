int redLed=10;
int greenLed=1;
int blueLed=4;

void setup() {
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);
}

void loop() {
  RGB_color(255,0,0);
  delay(500);
  RGB_color(0,255,0);
  delay(500);
  RGB_color(0,0,255);
  delay(500);
  RGB_color(255,255,255);
  delay(500);
  RGB_color(255,165,0);
  delay(500);
  RGB_color(156,34,93);
  delay(500);
}

void RGB_color(int red,int green,int blue)
{
  analogWrite(redLed,red);
  analogWrite(greenLed,green);
  analogWrite(blueLed,blue);
}