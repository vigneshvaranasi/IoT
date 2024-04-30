#include <ESP8266WiFi.h>

const char *ssid = "VVSV";         // Your Wi-Fi Name
const char *password = "varanasi"; // Wi-Fi Password
int LED = 2;                       // led connected to GPIO2 (D4)
WiFiServer server(80);           

void setup()
{
    Serial.begin(115200); 
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
    server.begin(); // Starts the Server
    Serial.print("IP Address of network:"); // will print IP address on Serial Monitor
    Serial.println(WiFi.localIP());
}

void loop()
{
    WiFiClient client = server.available();
    String request = client.readStringUntil('\r');
    client.flush();
    int value = LOW;
    if (request.indexOf("/LED=ON") != -1)
    {
        digitalWrite(LED, HIGH); // Turn LED ON
        value = HIGH;
    }
    if (request.indexOf("/LED=OFF") != -1)
    {
        digitalWrite(LED, LOW); // Turn LED OFF
        value = LOW;
    }

    // HTML Page Code
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.print("CONTROL LED:");

    if (value == HIGH)
        client.print("ON");
    else
        client.print("OFF");

    client.println("<br>");
    client.println("<a href=\"/LED=ON\"><button>ON</button></a>");
    client.println("<a href=\"/LED=OFF\"><button>OFF</button></a>");
    client.println("</html>");
}