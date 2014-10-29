/**
 * Arduino - Serial Radio Frequency Driver
 * 
 * SerialRadioFrequencyAPC220.cpp
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_CPP__
#define __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_CPP__ 1

#include "SerialRadioFrequencyAPC220.h"

SerialRadioFrequencyAPC220::SerialRadioFrequencyAPC220(unsigned char rxPin,
        unsigned char txPin, unsigned char enPin, unsigned char setPin) :
        SerialRadioFrequency(rxPin, txPin) {
    this->enPin = enPin;
    this->setPin = setPin;
    pinMode(enPin, OUTPUT);
    pinMode(setPin, OUTPUT);
    digitalWrite(enPin, HIGH);
    digitalWrite(setPin, HIGH);
}

void SerialRadioFrequencyAPC220::setFrequency(const char* frequency) {
    for (unsigned char i = 0; i < 6; i++) {
        this->frequency[i] = frequency[i];
    }
}

const char* SerialRadioFrequencyAPC220::getFrequency() {
    this->frequency[6] = 0;
    return (const char*) this->frequency;
}

void SerialRadioFrequencyAPC220::setAirRate(unsigned char airRate) {
    this->airRate = airRate;
}

unsigned char SerialRadioFrequencyAPC220::getAirRate() {
    return this->airRate;
}

unsigned char SerialRadioFrequencyAPC220::getPower() {
    return this->power;
}

void SerialRadioFrequencyAPC220::setPower(unsigned char power) {
    this->power = power;
}

void SerialRadioFrequencyAPC220::setUartRate(unsigned char uartRate) {
    this->uartRate = uartRate;
}

unsigned char SerialRadioFrequencyAPC220::getUartRate() {
    return this->uartRate;
}

void SerialRadioFrequencyAPC220::setSeriesCheckout(
        unsigned char seriesCheckout) {
    this->seriesCheckout = seriesCheckout;
}

unsigned char SerialRadioFrequencyAPC220::getSeriesCheckout() {
    return this->seriesCheckout;
}

void SerialRadioFrequencyAPC220::readParameters() {
    unsigned char cmd[] = {0x52, 0x44, 0x0D, 0x0A};
    digitalWrite(this->enPin, HIGH);
    digitalWrite(this->setPin, HIGH);
    delay(50);
    digitalWrite(this->setPin, LOW);
    delay(1);
    for (unsigned char i = 0; i < 4; i++) {
        write(cmd[i]);
    }
    delay(200);
    for (unsigned char i = 0; i < 21; i++) {
        while (!available())
            ;
        answer[i] = (unsigned char) read();
    }
    delay(10);
    digitalWrite(this->setPin, HIGH);
    for (unsigned char i = 0; i < 6; i++) {
        this->frequency[i] = (unsigned char) answer[5 + i];
    }
    this->airRate = (unsigned char) answer[12];
    this->power = (unsigned char) answer[14];
    this->uartRate = (unsigned char) answer[16];
    this->seriesCheckout = (unsigned char) answer[18];
}

void SerialRadioFrequencyAPC220::writeParameters() {
    unsigned char cmd[] = {0x57, 0x52, 0x20, 0x34, 0x33, 0x34, 0x30, 0x30, 0x30,
            0x20, 0x33, 0x20, 0x39, 0x20, 0x30, 0x20, 0x30, 0x0D, 0x0A};
    digitalWrite(this->enPin, HIGH);
    digitalWrite(this->setPin, HIGH);
    delay(50);
    digitalWrite(this->setPin, LOW);
    delay(1);
    for (unsigned char i = 0; i < 6; i++) {
        cmd[3 + i] = frequency[i];
    }
    cmd[10] = airRate;
    cmd[12] = power;
    cmd[14] = uartRate;
    cmd[16] = seriesCheckout;
    for (unsigned char i = 0; i < 19; i++) {
        write(cmd[i]);
    }
    delay(200);
    for (unsigned char i = 0; i < 21; i++) {
        while (!available())
            ;
        answer[i] = (unsigned char) read();
    }
    delay(10);
    digitalWrite(this->setPin, HIGH);
}

#endif /* __ARDUINO_DRIVER_SERIAL_RADIO_FREQUENCY_APC220_CPP__ */
