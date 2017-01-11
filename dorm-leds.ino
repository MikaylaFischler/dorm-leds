/*
  Dorm LED Project: main.ino
  Main file for the LED project.

  Created by: Michael Fischler
  9/20/2016 @ WPI
*/

// Standard C++ Library
#include <unwind-cxx.h>
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <utility.h>

// LED Library
#include <Adafruit_NeoPixel.h>

// Configuration
#include "conf/config.h"
#include "conf/strips.h"

// Threading System
#include "lib/strip_id.h"
#include "lib/strip_ownership.h"

#include "lib/MemObj.cpp"
#include "lib/LocalStack.cpp"
#include "lib/Animation.cpp"
#include "lib/Thread.cpp"
#include "lib/ThreadHandler.cpp"

// Animations
#include "def/animations.h"

// Utility Files
#include "util/led.c"
#include "util/mem.c"
#include "util/MemoryFree.h"

// Timing
unsigned long int prev_time = millis();
unsigned long int cur_time = millis();

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(115200);
	Serial.println(F("Initializing..."));

	// random seed
	Serial.println(F("Generating random seed..."));
	randomSeed(analogRead(0));

	// initialize pins
	Serial.println(F("Setting pin modes..."));
	set_pin_modes();

	// initialize LED strips and set them to off
	Serial.println(F("Initializing neopixel strips..."));
	init_strips();

	// manual queue
	mem_available = freeMemory();
	Serial.println(F("Manually queueing animations..."));
	led_man_queue();

	// initialize timing
	Serial.println(F("Initializing timing system..."));
	init_timing();

	Serial.println(F("System Initialized."));
}

// the loop function runs over and over again forever
void loop() {
	// Run multithreaded system code
	led_main_loop();
	ctrl_main_loop();

	Serial.print(F("Free SRAM: "));
	Serial.print(freeMemory());
	Serial.println(F(" bytes"));
}
