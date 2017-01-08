/*
  Dorm LED Project: led_subsystem.ino
  This file manages timing and execution of LED commands.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

unsigned long int dT = 0;

ThreadHandler led_thread_handler = ThreadHandler();

void led_man_queue() {
	led_thread_handler.queue(deskBothWhitePurplePurpleFade);
	led_thread_handler.queue(win1Snow);

	Serial.println("----------------------");
	Serial.println("Manual Queue:");

	std::vector<Thread&> t = led_thread_handler.listThreads();
	for (int a = 0; a < t.size(); a++) {
		Animation anim = t.at(a).getAnimation();
		String name = anim.getName();
		Serial.println(name);
	}

	Serial.println("----------------------");
}

void led_main_loop() {
	// set change in time
	cur_time = millis();
	dT = cur_time - prev_time;

	// tell each thread the time change
	led_thread_handler.updateTimeAccumulated(dT);

	// execute commands that it is time to execute
	led_thread_handler.executeTick();

	// save this time as previous time
	prev_time = millis();

	// prevent ticks less than a millisecond
	delay(1);
}
