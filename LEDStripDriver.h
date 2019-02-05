#ifndef __LEDStripDriver_H__
#define __LEDStripDriver_H__

#include <Arduino.h>


class LEDStripDriver {
    public:
        // constructors
        LEDStripDriver(int8_t din, int8_t cin);
        LEDStripDriver(int8_t din, int8_t cin, int8_t delay);

        // color manipulation
        void setColorRGB(uint8_t red, uint8_t green, uint8_t blue);
        void setColorHEX(uint32_t hex);
        void setColorOff();

    private:
        int8_t _din, _cin, _delay;

        void senddata(uint32_t dx);
        void sendzero();
        void sendclock();
        uint8_t getColorCode(uint8_t color);
};

#endif
