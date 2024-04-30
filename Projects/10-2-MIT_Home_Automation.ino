#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

WiFiClient client;
unsigned long counterChannelNumber = 2487036;         // Channel ID
const char *myCounterReadAPIKey = "UEW8WV4NCGK3XIBK"; // Read API Key
const int FieldNumber1 = 1;                           // The field you wish to read
const int FieldNumber2 = 2;                           // The field you wish to read

void setup()
{
  pinMode(13, OUTPUT); // D7
  Serial.begin(115200);
  WiFi.begin("VVSV", "varanasi"); // write wifi name & password
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\nWIFI Connected");
  ThingSpeak.begin(client);
}

void loop()
{
  int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
  digitalWrite(13, A);
}