/*
  Dorm LED Project: led_subsystem.ino
  This file manages timing and execution of LED commands.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

unsigned long int dT = 0;

ThreadHandler led_thread_handler;

void led_man_queue() {
  led_thread_handler.queue(deskBothWhitePurplePurpleFade, 10);
  //led_thread_handler.queue(&winAllPurpleFade, 10);
  //led_thread_handler.queue(&win1RainbowWipe, 50);
  //led_thread_handler.queue(&win2RainbowWipe, 50);
  //led_thread_handler.queue(&win3RainbowWipe, 50);
  //led_thread_handler.queue(&winAllHalloweenFade, 5);
  //led_thread_handler.queue(&winAllHalloweenSparkle, 10);

  Serial.println("Queue: ");

  std::vector<Thread*> t = led_thread_handler.listThreads();
  for(int a = 0; a < t.size(); a++){
    Command* cmd = t.at(a)->getCMD();
    Command c = *cmd;
    Serial.println(c.getName());
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
