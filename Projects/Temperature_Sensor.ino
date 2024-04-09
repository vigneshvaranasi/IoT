// Download DHT Library by searching --> "DHT sensor library" and install

#include <DHT.h>
#define DHTPIN 8
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  delay(2000);

  float temperature = dht.readTemperature(); // Read temperature as Celsius
  float humidity = dht.readHumidity(); // Read humidity

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println();
}
