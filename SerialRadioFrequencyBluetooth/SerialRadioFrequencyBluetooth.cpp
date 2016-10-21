/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_CPP__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_CPP__ 1

#include "SerialRadioFrequencyBluetooth.h"

SerialRadioFrequencyBluetooth::SerialRadioFrequencyBluetooth(unsigned char rxPin,
        unsigned char txPin) :
        SoftwareSerialAttentionDevice(rxPin, txPin), boudRate(3) {
}

bool SerialRadioFrequencyBluetooth::setUartRate(unsigned char rate) {
    boudRate = rate;
    print("AT+BAUD");
    const char cmd[] = "1";
    cmd[0] += rate % 6;
    return sendCommandExpecting(cmd, "OK");
}

unsigned char SerialRadioFrequencyBluetooth::getUartRate() {
    return boudRate;
}

bool SerialRadioFrequencyBluetooth::setDeviceName(const char *name) {
    print("AT+NAME");
    return sendCommandExpecting(name, "OK");
}

bool SerialRadioFrequencyBluetooth::setDevicePin(const char *pin) {
    print("AT+PIN");
    return sendCommandExpecting(pin, "OK");
}

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_CPP__ */
