# Full Color RGB LED Strip Driver Module Shield for Arduino

This library is made for this kind of modules
![RGB LED Strip Driver Module Shield](https://raw.githubusercontent.com/MrKrabat/LED-Strip-Driver-Module/master/images/shield.jpg "RGB LED Strip Driver Module Shield")

**Do not connect 12V to the driver module while your Arduino is connected to your PC!**

Example usage:
```c
#include <LEDStripDriver.h>

// use two available GPIO pins from your board
// DIN=GPIO16, CIN=GPIO14 in this example
LEDStripDriver led = LEDStripDriver(16, 14);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  led.setColor(255, 0, 0); // RGB
  delay(1000);
  led.setColor("#00FF00"); // String
  delay(1000);
  led.setColor(0x0000FF); // HEX
  delay(1000);
  led.setColor(); // turn off
  delay(1000);
}
```