#ifndef __LEDStripDriver_H__
#define __LEDStripDriver_H__

#include <Arduino.h>


class LEDStripDriver {
    public:
        // constructors
        LEDStripDriver(int8_t din, int8_t cin);
        LEDStripDriver(int8_t din, int8_t cin, int16_t delay);

        // color manipulation
        void setColor(uint8_t red, uint8_t green, uint8_t blue);
        void setColor(uint32_t hex);
        void setColor(String str);
        void setColor();

    private:
        int8_t _din, _cin;
        int16_t _delay;

        // private methods
        uint8_t getColorCode(uint8_t color);
        void senddata(uint32_t dx);
        void sendzero();
        void sendclock();
};

#endif
