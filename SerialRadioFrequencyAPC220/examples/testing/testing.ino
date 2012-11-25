#include <SoftwareSerial.h>
#include <RfSerial.h>

RfSerial serial(2, 3, 4, 5);

void setup() {

  Serial.begin(9600);

  Serial.println("Are you sure to continue? (y/n)");
  while (!Serial.available());
  while (Serial.read() != 'y');
  
  serial.begin(9600);
  serial.readParameters();

  Serial.println(serial.getFrequency());
  Serial.println((char)serial.getAirRate());
  Serial.println((char)serial.getPower());
  Serial.println((char)serial.getUartRate());
  Serial.println((char)serial.getSeriesCheckout());
}

void loop() {
}
