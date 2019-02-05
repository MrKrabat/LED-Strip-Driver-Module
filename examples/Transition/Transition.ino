#include <LEDStripDriver.h>

// use two available GPIO pins from your board
// DIN=GPIO16, CIN=GPIO14 in this example
LEDStripDriver led = LEDStripDriver(16, 14);


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for (uint16_t color = 0; color < 256; color++) {
    led.setColor(color, color, color);
    delay(10);
  }

  led.setColor();
  delay(2000);
}
