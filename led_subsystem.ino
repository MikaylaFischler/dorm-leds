/*
  Dorm LED Project: led_subsystem.ino
  This file manages timing and execution of LED commands.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

void led_man_queue() {
	thread_handler.queue(new Animation_Static_DeskThirdDimAmbient());
	thread_handler.queue(new Animation_Seasonal_Winter_Snow_Win1());
	thread_handler.queue(new Animation_Simple_Win2RainbowWipe());
	thread_handler.queue(new Animation_Seasonal_Winter_Snow_Win3());

	Serial.println(F("----------------------"));
	Serial.println(F("Manual Queue Contains:"));

	std::vector<Thread*> t = thread_handler.listThreads();
	for (unsigned int i = 0; i < t.size(); i++) {
		Animation* anim = t.at(i)->getAnimation();
		String name = anim->getName();
		Serial.println(name);
	}

	Serial.println(F("----------------------"));
}
