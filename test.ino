/* Test Code for the Dorm LED System */

// Test LEDs using the code from strandtest.ino
void test(Adafruit_NeoPixel strip) {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip, strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip, strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip, strip.Color(0, 0, 255), 50); // Blue
  
  // Send a theater pixel chase in...
  theaterChase(strip, strip.Color(127, 127, 127), 50); // White
  theaterChase(strip, strip.Color(127, 0, 0), 50);     // Red
  theaterChase(strip, strip.Color(0, 0, 127), 50);     // Blue

  rainbow(strip, 20);
  rainbowCycle(strip, 20);
  theaterChaseRainbow(strip, 50);
}

// Full test of LEDs using the code from strandtest.ino
void fulltest() {
  // Some example procedures showing how to display to the pixels:
  allColorWipe(window1.Color(255, 0, 0), 50); // Red
  allColorWipe(window1.Color(0, 255, 0), 50); // Green
  allColorWipe(window1.Color(0, 0, 255), 50); // Blue
  
  // Send a theater pixel chase in...
  allTheaterChase(window1.Color(127, 127, 127), 50); // White
  allTheaterChase(window1.Color(127, 0, 0), 50);     // Red
  allTheaterChase(window1.Color(0, 0, 127), 50);     // Blue

  allRainbow(20);
  allRainbowCycle(20);
  allTheaterChaseRainbow(50);
}

// Fill the dots one after the other with a color
void allColorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < window1.numPixels(); i++) {
    setAllWindowPixelColor(i, c);
    showAllWindowStrips();
    
    delay(wait);
  }
}

void allRainbow(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256; j++) {
    for(i = 0; i < window1.numPixels(); i++) {
      setAllWindowPixelColor(i, Wheel((i + j) & 255));
    }
    
    showAllWindowStrips();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void allRainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for(i = 0; i < window1.numPixels(); i++) {
      setAllWindowPixelColor(i, Wheel(((i * 256 / window1.numPixels()) + j) & 255));
    }
    
    showAllWindowStrips();
    delay(wait);
  }
}

// Theatre-style crawling lights.
void allTheaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) {  // do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < window1.numPixels(); i = i + 3) {
        setAllWindowPixelColor(i + q, c); // turn every third pixel on
      }
      
      showAllWindowStrips();

      delay(wait);

      for (uint16_t i = 0; i < window1.numPixels(); i = i + 3) {
        setAllWindowPixelColor(i + q, 0); // turn every third pixel off
      }
    }
  }
}

// Theatre-style crawling lights with rainbow effect
void allTheaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) { // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < window1.numPixels(); i = i + 3) {
        setAllWindowPixelColor(i + q, Wheel((i + j) % 255)); // turn every third pixel on
      }
      
      showAllWindowStrips();

      delay(wait);

      for (uint16_t i = 0; i < window1.numPixels(); i = i + 3) {
        setAllWindowPixelColor(i + q, 0); // turn every third pixel off
      }
    }
  }
}
