/*
  Dorm LED Project: main.ino
  Main file for the LED project.

  Created by: Michael Fischler
  9/20/2016 @ WPI
*/

// Arduino Standard C++ Library
#include <unwind-cxx.h>
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <utility.h>

// Arduinio Boost Library
#include <boost_1_51_0.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/any.hpp>

// Threading System
#include "lib/Strip.h"
#include "lib/LocalStack.cpp"
#include "lib/Command.cpp"
#include "lib/Thread.cpp"
#include "lib/ThreadHandler.cpp"

// LED Library
#include <Adafruit_NeoPixel.h>

// Configuration
#include "conf/config.h"
#include "conf/strips.h"

// Utility Files
#include "util/led.c"

// Commands
#include "def/led_desk_anim_cmds.cpp"
#include "def/led_window_anim_cmds.cpp"
#include "def/led_commands.cpp"

// Timing
unsigned long int prev_time = millis();
unsigned long int cur_time = millis();

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  Serial.println("init");

  // random seed
  randomSeed(analogRead(0));

  // initialize pins
  set_pin_modes();

  // initialize LED strips and set them to off
  init_strips();

  // manual queue
  led_man_queue();

  // initialize timing
  init_timing();
}

// the loop function runs over and over again forever
void loop() {
  // Run multithreaded system code
  led_main_loop();

  //fulltest();
  //ctrl_main_loop();
}
