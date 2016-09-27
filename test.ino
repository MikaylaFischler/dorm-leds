/* Test Code for the Dorm LED System */

// Test LEDs using the code from strandtest.ino
void test(Adafruit_NeoPixel strip) {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50);     // Red
  theaterChase(strip.Color(0, 0, 127), 50);     // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

