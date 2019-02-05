#include <Arduino.h>

#include "LEDStripDriver.h"


/**************************************************************************/
/*!
    @brief class constructor
    @param din the data pin to use
    @param cin the clock pin to use
*/
/**************************************************************************/
LEDStripDriver::LEDStripDriver(int8_t din, int8_t cin) : _din(din), _cin(cin), _delay(20) {
    pinMode(din, OUTPUT);
    pinMode(cin, OUTPUT);
}

/**************************************************************************/
/*!
    @brief class constructor
    @param din the data pin to use
    @param cin the clock pin to use
    @param delay the clock delay in microseconds
*/
/**************************************************************************/
LEDStripDriver::LEDStripDriver(int8_t din, int8_t cin, int8_t delay) : _din(din), _cin(cin), _delay(delay) {
    pinMode(din, OUTPUT);
    pinMode(cin, OUTPUT);
}

void LEDStripDriver::setColorRGB(uint8_t red, uint8_t green, uint8_t blue) {
    uint32_t dx = 0;
    dx |= (uint32_t)0x03 << 30;
    dx |= (uint32_t)getColorCode(blue) << 28;
    dx |= (uint32_t)getColorCode(green) << 26;
    dx |= (uint32_t)getColorCode(red) << 24;

    dx |= (uint32_t)blue << 16;
    dx |= (uint32_t)green << 8;
    dx |= red;

    senddata(dx);
}

void LEDStripDriver::setColorHEX(uint32_t hex) {
    uint8_t red   = (hex >> 16) & 0xFF;
    uint8_t green = (hex >> 8) & 0xFF;
    uint8_t blue  = (hex) & 0xFF;
    setColorRGB(red, green, blue);
}

void LEDStripDriver::setColorOff() {
    setColorRGB(0, 0, 0);
}

void LEDStripDriver::senddata(uint32_t dx) {
    sendzero();
    for (uint8_t i = 0; i < 32; i++) {
        if ((dx & 0x80000000) != 0) {
            digitalWrite(_din, HIGH);
        } else {
            digitalWrite(_din, LOW);
        }
        dx <<= 1;
        sendclock();
    }
    //sendzero();
}

void LEDStripDriver::sendzero() {
    for (uint8_t i = 0; i < 32; i++) {
        digitalWrite(_din, LOW);
        sendclock();
    }
}

void LEDStripDriver::sendclock() {
    digitalWrite(_cin, LOW);
    delayMicroseconds(_delay);
    digitalWrite(_cin, HIGH);
    delayMicroseconds(_delay);
}

uint8_t LEDStripDriver::getColorCode(uint8_t color) {
    uint8_t tmp = 0;
    if ((color & 0x80) == 0) {
        tmp |= 0x02;
    }
    if ((color & 0x40) == 0) {
        tmp |= 0x01;
    }
    return tmp;
}
