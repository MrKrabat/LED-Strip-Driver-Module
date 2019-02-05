# Full Color RGB LED Strip Driver Module Shield for Arduino

This library is made for this kind of modules
![RGB LED Strip Driver Module Shield](https://raw.githubusercontent.com/MrKrabat/LED-Strip-Driver-Module/master/images/shield.jpg "RGB LED Strip Driver Module Shield")

**Do not connect 12V to the driver module while your Arduino is connected to your PC!**

Example usage:
```c
#include <LEDStripDriver.h>

// use two avaiable GPIO pins from your board
// DIN=GPIO16, CIN=GPIO14 in this example
LEDStripDriver led = LEDStripDriver(16, 14);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  led.setColorRGB(0, 255, 0); // green
  delay(1000);
  led.setColorHEX(0xFFFFFF); // white
  delay(1000);
  led.setColorOff(); // off
  delay(1000);
}
```