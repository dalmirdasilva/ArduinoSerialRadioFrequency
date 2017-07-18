#include <SoftwareSerial.h>
#include <SerialRadioFrequency.h>
#include <SerialRadioFrequencyBluetooth.h>

SerialRadioFrequencyBluetooth serial(2, 3);

void setup() {
  Serial.begin(9600);

  Serial.println("Are you sure to continue? (y/n)");
  while (!Serial.available());
  while (Serial.read() != 'y');
  Serial.println("Continuing...");
    
  serial.begin(9600);

  char name[64];
  Serial.println(serial.getDeviceName(name));
  Serial.println(name);
  Serial.println("Setup done.");
}

void loop() {
  if (serial.available()) {
    char b = serial.read();
    Serial.print(b);
  }
}
