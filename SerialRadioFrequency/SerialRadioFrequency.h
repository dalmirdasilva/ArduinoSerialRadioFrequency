/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * SerialRadioFrequency.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_H__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_H__ 1

#include <Arduino.h>
#include <SoftwareSerial.h>

class SerialRadioFrequency : public SoftwareSerial {
    
public:

    SerialRadioFrequency(unsigned char rxPin, unsigned char txPin);
};

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_H__ */
