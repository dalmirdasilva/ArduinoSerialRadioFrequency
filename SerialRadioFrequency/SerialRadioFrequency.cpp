/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * SerialRadioFrequency.cpp
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_CPP__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_CPP__ 1

#include "SerialRadioFrequency.h"

SerialRadioFrequency::SerialRadioFrequency(unsigned char rxPin,
        unsigned char txPin) :
        SoftwareSerial(rxPin, txPin) {
}

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_CPP__ */
