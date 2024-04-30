#include <ThingSpeak.h>
#include <ESP8266WiFi.h>

WiFiClient client;
unsigned long ChannelNumber = 2487036; // Channel ID
const char *API = "UEW8WV4NCGK3XIBK"; // Read API Key

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
  Serial.print("WIFI Connected");
  ThingSpeak.begin(client);
}

void loop()
{
  int A = ThingSpeak.readLongField(ChannelNumber, 1, API);
  digitalWrite(13, A);
}