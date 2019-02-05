#include <LEDStripDriver.h>

// change this pins according to your setup
LEDStripDriver led = LEDStripDriver(16, 14);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  led.setColor(255, 0, 0);
  delay(1000);
  led.setColor("#00FF00");
  delay(1000);
  led.setColor(0x0000FF);
  delay(1000);
  led.setColor();
  delay(1000);
}
