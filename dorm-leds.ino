/*!
	@file dorm-leds.ino
	@brief Dorm LED Project<br/>
		Arduino project file for the LED project.
	@author Mikayla Fischler
	@date 2016/09/20
*/

// Standard C++ Library
#include <unwind-cxx.h>
#include <ArduinoSTL.h>
#include <system_configuration.h>
#include <vector>

// LED Libraries (NeoPixel for RGBW!)
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>

// Configuration
#include "conf/config.h"
#include "conf/dev_types.h"

// System
#include "lib/Thread.cpp"
#include "lib/ThreadHandler.cpp"

#include "lib/device/Device.cpp"
#include "lib/device/DeviceManager.cpp"

#include "lib/exe/Executable.cpp"
#include "lib/exe/Animation.cpp"
#include "lib/exe/Process.hpp"

#include "lib/neopixel/NeoPixelStripManager.cpp"
#include "lib/neopixel/NeoPixelStripGroup.cpp"
#include "lib/neopixel/VirtualNeoPixelStrip.cpp"

// Animations
#include "def/animations.h"

// Devices (like drivers)
#include "dev/devices.h"

// Utility Files
#include "util/led.c"
#include "util/free_memory.c"

// Globals
#include "conf/globals.h"

// Timing
unsigned long int prev_time; //!< millis() time at end of previous iteration
unsigned long int cur_time; //!< current millis() time

// Core System Variables and Class Instances
unsigned long int dT = 0; //!< elapsed time across iterations
ThreadHandler thread_handler = ThreadHandler(); //!< global multi-threading system

/*!
	@brief System Initialization
 	The setup function runs once when you press reset or power the board.
	Sets-up all parts of the system and is responsibile for initialization.
*/
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
	Serial.println(F("Initializing NeoPixel strips..."));
	npsm = NeoPixelStripManager();
	init_strips();

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

/*!
	@brief Main Loop
	The loop function runs over and over again forever.
	Runs multithreaded system code.
*/
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
	Serial.println(dT); // takes ~200us

	// print memory
	//Serial.print(F("Free SRAM: "));
	//Serial.print(freeMemory());
	//Serial.println(F(" bytes"));
}
