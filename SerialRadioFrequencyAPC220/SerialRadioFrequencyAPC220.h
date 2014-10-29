/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * SerialRadioFrequencyAPC220.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_H__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_H__ 1

#include <Arduino.h>
#include <SerialRadioFrequency.h>

class SerialRadioFrequencyAPC220 : public SerialRadioFrequency {

    /**
     * The EN pin
     */
    unsigned char enPin;

    /**
     * The SET pin
     */
    unsigned char setPin;

    /**
     * The device frequency.
     * 
     * 418MHz-455MHz. Default: 434 MHz.
     */
    unsigned char frequency[7];

    /**
     * The device air rate.
     * 
     * 1, 2, 3 and 4 refer to 2400, 4800, 9600, 19200bps separately. Default: 9600.
     */
    unsigned char airRate;

    /**
     * The device power.
     * 
     * 0 to 9, 9 means 20dBm (100mW). Default: 9.
     */
    unsigned char power;

    /**
     * The device uartRate.
     * 
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately. Default: 9600.
     */
    unsigned char uartRate;

    /**
     * The device seriesCheckout.
     * 
     * Disable, Even Parity, Odd Parity. Default: Disable.
     */
    unsigned char seriesCheckout;

    /**
     * Communication buffer.
     */
    unsigned char answer[21];

public:

    SerialRadioFrequencyAPC220(unsigned char rxPin, unsigned char txPin,
            unsigned char enPin, unsigned char setPin);

    /**
     * Sets RF frequency.
     * 
     * Unit is KHz, for example 434MHz is 434000.
     * 
     * @param frequency         The frequency.
     */
    void setFrequency(const char* frequency);

    /**
     * Gets RF frequency.
     * 
     * Unit is KHz, for example 434MHz is 434000.
     * 
     * @return                  The frequency.
     */
    const char* getFrequency();

    /**
     * Sets the RF data rate.
     * 
     * 1, 2, 3 and 4 refer to 2400, 4800, 9600, 19200bps separately.
     * 
     * @param airRate             The data rate.
     */
    void setAirRate(unsigned char airRate);

    /**
     * Gets the RF data rate.
     * 
     * 1, 2, 3 and 4 refer to 2400, 4800, 9600, 19200bps separately.
     * 
     * @return                  The data rate.
     */
    unsigned char getAirRate();

    /**
     * Sets the power.
     * 
     * 0 to 9, 9 means 20dBm (100mW).
     * 
     * @param power             The power.
     */
    void setPower(unsigned char power);

    /**
     * Gets the power.
     * 
     * 0 to 9, 9 means 20dBm (100mW).
     * 
     * @return                  The power.
     */
    unsigned char getPower();

    /**
     * Sets the UART rate.
     * 
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     * 
     * @param rate          The UART rate.
     */
    void setUartRate(unsigned char rate);

    /**
     * Gets the UART rate.
     * 
     * 0, 1, 2, 3, 4, 5 and 6 refers to 1200, 2400, 4800, 9600, 19200, 38400, 57600bps separately.
     * 
     * @return              The UART rate.
     */
    unsigned char getUartRate();

    /**
     * Sets the series checkout.
     * 
     * Series checkout：0 means no check,1 means even parity,2 means odd parity.
     * 
     * @param checkout      The series checkout.
     */
    void setSeriesCheckout(unsigned char checkout);

    /**
     * Gets the series checkout.
     * 
     * Series checkout：0 means no check,1 means even parity,2 means odd parity.
     * 
     * @return              The series checkout.
     */
    unsigned char getSeriesCheckout();

    /**
     * Makes a read command.
     * 
     * RD↙
     * ANSWER: PARA_434000_3_9_0_0↙
     * ANSWER: PARA_frequency_rf data rate_output power_UART data rate_series checkout
     */
    void readParameters();

    /**
     * Makes a write command.
     * 
     * Send the current configuration to the device.
     */
    void writeParameters();
};

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_H__ */
