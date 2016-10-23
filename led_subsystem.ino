/*
  Dorm LED Project: led_subsystem.ino
  This file manages timing and execution of LED commands.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

unsigned long int dT = 0;

ThreadHandler led_thread_handler;

void led_man_queue() {
  led_thread_handler.queue(&deskBothThirdPurpleFade, 10);
  Serial.println("queued");

  Serial.print("Queue: ");
  Command* cmd = led_thread_handler.listThreads().at(0).getCMD();
  Command c = *cmd;
  Serial.println(c.getName());
  Serial.println("----------------------");
}

void led_main_loop() {
  Serial.println("> in main loop");
  // set change in time
  cur_time = millis();
  dT = cur_time - prev_time;

  Serial.print("dT: ");
  Serial.println(dT);

  Serial.print("Queue: ");
  Command* cmd = led_thread_handler.listThreads().at(0).getCMD();
  Command c = *cmd;
  Serial.println(c.getName());
  
  // tell each thread the time change
  led_thread_handler.updateTimeAccumulated(dT);

  // execute commands that it is time to execute
  led_thread_handler.executeTick();

  // save this time as previous time
  prev_time = millis();
}

