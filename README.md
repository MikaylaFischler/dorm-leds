# dorm-leds
Arduino Code for Adafruit NeoPixels in my WPI dorm room. It consists of three windows with the inside border lined with 30 LED/m Adafruit NeoPixel strips and two smaller strips providing lighting to my desk.

As stated in the description, this is probably not the best thing for Arduino/C/C++ beginners to look at for examples of the NeoPixel library, which I am saying since GitHub just added those nice new "topic" tags and someone might actually eventually stumble upon this.

Hopefully I'll add documentation in the future.

On "completion" of this project, specifically the library, in addition to possible increased abstraction, I may release this as a library for others to implement (with actual documentation).

### Dependencies

This code depends on the [Adafruit_Neopixel Library](https://github.com/adafruit/Adafruit_NeoPixel) and the [StandardCplusplus Library](https://github.com/maniacbug/StandardCplusplus).

### File Structure

#### /
*Project Root*<br>
dorm-leds.ino
- The main file for the entire project. Includes all files and calls initialization functions. After initialization, runs loop with thread handler execution.

init.ino
- The initialization code for the project. Begins LED strips and queues default animations and processes.

#### /conf/
*Configuration*<br>
config.h
- Defines all the ports used in the project, the length of the LED strips, and the type of LED strip used.

strips.h
- Constructors for each LED strip. Note; window_generic is used to call the Color() function, which will soon be replaced by my own copy of that so I don't need to initialize an unnecessary object.

#### /def
*Animation Definitions*<br>

#### /dev
*Device Interface Files*<br>

#### /lib
*The Core Library*<br>

#### /proc
*Process Definitions*<br>
