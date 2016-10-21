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

class SerialRadioFrequency {

public:

    /**
     * Sets the UART rate.
     *
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     *
     * @param rate          The UART rate.
     */
    virtual void setUartRate(unsigned char rate) = 0;

    /**
     * Gets the UART rate.
     *
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     *
     * @return              The UART rate.
     */
    virtual unsigned char getUartRate() = 0;
};

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_H__ */
