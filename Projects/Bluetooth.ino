#include <SoftwareSerial.h>

SoftwareSerial bt(2, 3); // (Rx, Tx)

void setup() {
  bt.begin(9600); // Define baud rate for software serial communication
  Serial.begin(9600); // Define baud rate for serial communication

  // Change Bluetooth module name
  bt.print("AT+NAMEvignesh\r\n");
  delay(100); // Delay to ensure the command is fully transmitted
}

void loop() {
  if (bt.available()) {
    Serial.write(bt.read()); // Print character received onto the serial monitor
  }
}
