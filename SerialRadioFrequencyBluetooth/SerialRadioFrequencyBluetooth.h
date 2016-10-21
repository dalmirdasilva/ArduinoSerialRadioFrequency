/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_H__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_H__ 1

#include <Arduino.h>
#include <SerialRadioFrequency.h>
#include <SoftwareSerialAttentionDevice.h>

class SerialRadioFrequencyBluetooth: public SerialRadioFrequency, public SoftwareSerialAttentionDevice {

    unsigned char boudRate;

public:

    virtual ~SerialRadioFrequencyBluetooth() {
    }

    SerialRadioFrequencyBluetooth(unsigned char rxPin, unsigned char txPin);

    /**
     * Sets the UART rate.
     *
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     *
     * @param rate          The UART rate.
     */
    bool setUartRate(unsigned char rate);

    /**
     * Gets the UART rate.
     *
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     *
     * @return              The UART rate.
     */
    unsigned char getUartRate();

    /**
     * Set bluetooth device name
     *
     * @param const char* Device name
     */
    bool setDeviceName(const char *name);

    /**
     * Set bluetooth device PIN
     *
     * @param const char* Device pin
     */
    bool setDevicePin(const char *pin);
};

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_BLUETOOTH_H__ */
