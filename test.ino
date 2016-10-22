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
  allColorWipe(window_generic.Color(255, 0, 0), 50); // Red
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(255, 50, 0), 50); // Orange
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(255, 150, 0), 50); // Yellow
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(0, 255, 0), 50); // Green
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(0, 255, 200), 50); // Sea Green
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(0, 0, 255), 50); // Blue
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(100, 0, 255), 50); // Indigo
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  allColorWipe(window_generic.Color(255, 0, 255), 50); // Violet
  allColorWipe(window_generic.Color(0, 0, 0), 50); // Off
  
  // Send a theater pixel chase in...
  allTheaterChase(window_generic.Color(127, 127, 127), 50); // White
  allTheaterChase(window_generic.Color(127, 0, 0), 50);     // Red
  allTheaterChase(window_generic.Color(0, 0, 127), 50);     // Blue

  allRainbow(20);
  allRainbowCycle(20);
  allTheaterChaseRainbow(50);
}

// Fill the dots one after the other with a color
void allColorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i = 0; i < WINDOW_LENGTH; i++) {
    setAllWindowPixelColor(i, c);
    showAllWindowStrips();
    
    delay(wait);
  }
}

void allRainbow(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256; j++) {
    for(i = 0; i < window_generic.numPixels(); i++) {
      setAllWindowPixelColor(i, Wheel(window_generic, (i + j) & 255));
    }
    
    showAllWindowStrips();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void allRainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for(i = 0; i < WINDOW_LENGTH; i++) {
      setAllWindowPixelColor(i, Wheel(window_generic, ((i * 256 / WINDOW_LENGTH) + j) & 255));
    }
    
    showAllWindowStrips();
    delay(wait);
  }
}

// Theatre-style crawling lights.
void allTheaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) {  // do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < WINDOW_LENGTH; i = i + 3) {
        setAllWindowPixelColor(i + q, c); // turn every third pixel on
      }
      
      showAllWindowStrips();

      delay(wait);

      for (uint16_t i = 0; i < WINDOW_LENGTH; i = i + 3) {
        setAllWindowPixelColor(i + q, 0); // turn every third pixel off
      }
    }
  }
}

// Theatre-style crawling lights with rainbow effect
void allTheaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) { // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < WINDOW_LENGTH; i = i + 3) {
        setAllWindowPixelColor(i + q, Wheel(window_generic, (i + j) % 255)); // turn every third pixel on
      }
      
      showAllWindowStrips();

      delay(wait);

      for (uint16_t i = 0; i < WINDOW_LENGTH; i = i + 3) {
        setAllWindowPixelColor(i + q, 0); // turn every third pixel off
      }
    }
  }
}
