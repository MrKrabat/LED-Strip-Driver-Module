#include <LEDStripDriver.h>

// change this pins according to your setup
LEDStripDriver led = LEDStripDriver(16, 14);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  led.setColorRGB(255, 0, 0);
  delay(1000);
  led.setColorRGB(0, 255, 0);
  delay(1000);
  led.setColorHEX(0x0000FF);
  delay(1000);
  led.setColorOff();
  delay(1000);
}
