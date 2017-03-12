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

// Liquid Crystal Display Library
#include <LiquidCrystal.h>

// Configuration
#include "conf/config.h"
#include "conf/strips.h"
#include "conf/dev_types.h"

// System
#include "lib/strip_id.h"
#include "lib/strip_ownership.h"

#include "lib/MemObj.cpp"
#include "lib/LocalStack.cpp"

#include "lib/Executable.cpp"
#include "lib/Animation.cpp"
#include "lib/Process.cpp"

#include "lib/Thread.cpp"
#include "lib/ThreadHandler.cpp"

#include "lib/Device.cpp"
#include "lib/DeviceManager.cpp"

// Animations
#include "def/animations.h"

// Devices (like drivers)
#include "dev/devices.h"

// Utility Files
#include "util/led.c"
#include "util/mem.c"
#include "util/free_memory.c"

// Timing
unsigned long int prev_time;
unsigned long int cur_time;

// LCD Display
LiquidCrystal lcd(LCD_E_PIN, LCD_RS_PIN, LCD_D4_PIN, LDC_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);

// Core System Variables and Class Instances
unsigned long int dT = 0;
ThreadHandler thread_handler = ThreadHandler();

// Globals
#include "conf/globals.h"

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(250000);
	Serial.println(F("Initializing..."));

	// starting available memory
	Serial.print(freeMemory());
	Serial.println(F(" bytes of free SRAM."));

	// random seed
	Serial.println(F("Generating random seed..."));
	randomSeed(analogRead(RAND_SEED_ANALOG_NOISE_PORT));

	// initialize pins
	Serial.println(F("Setting pin modes..."));
	set_pin_modes();

	// initialize LED strips and set them to off
	Serial.println(F("Initializing neopixel strips..."));
	init_strips();

	// initialize LCD display
	Serial.println(F("Initializing LCD display..."));
	init_lcd();

	// mount other devices
	Serial.println(F("Mounting Additional Devices..."));
	device_manager = DeviceManager();
	mem_available = freeMemory();
	mount_devices();

	// manual queue
	Serial.println(F("Queueing system threads..."));
	mem_available = freeMemory();
	queue_sys_threads();

	// manual queue
	Serial.println(F("Manually queueing animations..."));
	mem_available = freeMemory();
	led_man_queue();

	// initialize timing
	Serial.println(F("Initializing timing system..."));
	init_timing();

	Serial.println(F("System Initialized."));
	Serial.print(freeMemory());
	Serial.println(F(" bytes of free SRAM."));
}

// the loop function runs over and over again forever
// run multithreaded system code
void loop() {
	// set change in time
	cur_time = millis();
	dT = cur_time - prev_time;

	// save this time as previous time
	prev_time = cur_time;

	// tell each thread the time change
	thread_handler.updateTimeAccumulated(dT);

	// execute commands that it is time to execute
	thread_handler.executeTick();

	// prevent ticks less than a millisecond
	delayMicroseconds(400);

	// print memory
	//Serial.print(F("Free SRAM: "));
	//Serial.print(freeMemory());
	//Serial.println(F(" bytes"));
}
