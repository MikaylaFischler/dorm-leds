/*
  Dorm LED Project: init.ino
  This file contains the initialization code for the dorm LED system.

  Created by: Michael Fischler
  9/30/2016 @ WPI
*/

void set_pin_modes() {
	// set pin modes here

	// select and disable pins
	pinMode(DISABLE_LED_PIN, OUTPUT);
	pinMode(DISABLE_BTN_PIN, INPUT);
	pinMode(SELECT_LED_PIN, OUTPUT);
	pinMode(SELECT_BTN_PIN, INPUT);

	// window control pins
	pinMode(MODE_WIN_LED_PIN, OUTPUT);
	pinMode(MODE_WIN_BTN_PIN, INPUT);
	pinMode(MODE_WIN3_LED_PIN, OUTPUT);
	pinMode(MODE_WIN3_BTN_PIN, INPUT);
	pinMode(MODE_WIN2_LED_PIN, OUTPUT);
	pinMode(MODE_WIN2_BTN_PIN, INPUT);
	pinMode(MODE_WIN1_LED_PIN, OUTPUT);
	pinMode(MODE_WIN1_BTN_PIN, INPUT);

	// desk control pins
	pinMode(MODE_DESK_LED_PIN, OUTPUT);
	pinMode(MODE_DESK_BTN_PIN, INPUT);
	pinMode(MODE_DESK2_LED_PIN, OUTPUT);
	pinMode(MODE_DESK2_BTN_PIN, INPUT);
	pinMode(MODE_DESK1_LED_PIN, OUTPUT);
	pinMode(MODE_DESK1_BTN_PIN, INPUT);
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

void init_lcd() {
	lcd.begin(16, 2);
	lcd.print(F("LED Control"));
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
	//thread_handler.queue(new Animation_Simple_DeskWhitePurpleFade());
	thread_handler.queue(new Animation_Static_DeskThirdDimAmbient());
	thread_handler.queue(new Animation_Simple_Indiv_Rainbow(&desk1));
	thread_handler.queue(new Animation_Simple_Indiv_Rainbow(&desk2));
	//thread_handler.queue(new Animation_Holiday_Halloween_WinAllHalloweenSparkle());
	thread_handler.queue(new Animation_Seasonal_Winter_WindowSnow(&window1));
	//thread_handler.queue(new Animation_Simple_Win2RainbowWipe());
	thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window2));
	//thread_handler.queue(new Animation_Simple_WinAllPurpleFade());
	thread_handler.queue(new Animation_Seasonal_Winter_WindowSnow(&window3));
}
