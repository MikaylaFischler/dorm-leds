/*
  Dorm LED Project: init.ino
  This file contains the initialization code for the dorm LED system.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

void set_pin_modes() {
	//set pin modes here

}

void init_strips() {
	// Window Strips
	window1.begin();
	window1.show();

	window2.begin();
	window2.show();

	window3.begin();
	window3.show();

	// Desk Strips
	desk1.begin();
	desk1.show();

	desk2.begin();
	desk2.show();
}

void init_timing() {
	prev_time = millis();
}

void queue_sys_threads() {
	// system processes
	//thread_handler.queue();
}

void led_man_queue() {
	// manually queue animations for startup
	thread_handler.queue(new Animation_Static_DeskDimAmbient());
	//thread_handler.queue(new Animation_Holiday_Halloween_WinAllHalloweenSparkle());
	thread_handler.queue(new Animation_Seasonal_Winter_Snow_Win1());
	thread_handler.queue(new Animation_Simple_Win2RainbowWipe());
	thread_handler.queue(new Animation_Seasonal_Winter_Snow_Win3());
}
