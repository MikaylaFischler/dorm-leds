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

void mount_devices() {
	// note: order matters; it defines the device index
																									// device id
	// equalizers
	device_manager.mount(new MSGEQ7(F("Left Equalizer"), EQ_L_STROBE, EQ_L_RESET, EQ_L_INPUT));		// 0
	device_manager.mount(new MSGEQ7(F("Right Equalizer"), EQ_R_STROBE, EQ_R_RESET, EQ_R_INPUT));	// 1

	// LED buttons
	device_manager.mount(new LEDButton(F("Desk 1 Mode"), MODE_DESK1_LED_PIN, MODE_DESK1_BTN_PIN));	// 2
	device_manager.mount(new LEDButton(F("Desk 2 Mode"), MODE_DESK2_LED_PIN, MODE_DESK2_BTN_PIN));	// 3
	device_manager.mount(new LEDButton(F("Desk Mode"), MODE_DESK_LED_PIN, MODE_DESK_BTN_PIN));		// 4

	device_manager.mount(new LEDButton(F("Win 1 Mode"), MODE_WIN1_LED_PIN, MODE_WIN1_BTN_PIN));		// 5
	device_manager.mount(new LEDButton(F("Win 2 Mode"), MODE_WIN2_LED_PIN, MODE_WIN2_BTN_PIN));		// 6
	device_manager.mount(new LEDButton(F("Win 3 Mode"), MODE_WIN3_LED_PIN, MODE_WIN3_BTN_PIN));		// 7
	device_manager.mount(new LEDButton(F("Window Mode"), MODE_WIN_LED_PIN, MODE_WIN_BTN_PIN));		// 8

	device_manager.mount(new LEDButton(F("Select"), SELECT_LED_PIN, SELECT_BTN_PIN));				// 9
	device_manager.mount(new LEDButton(F("Disable"), DISABLE_LED_PIN, DISABLE_BTN_PIN));			// 10
}

void queue_sys_threads() {
	// device processes
	thread_handler.queue(new MSGEQ7::UpdaterProcess(device_manager.getDevice<MSGEQ7>(0)));
	//thread_handler.queue(new MSGEQ7::UpdaterProcess(device_manager.getDevice<MSGEQ7>(1)));

	// system processes
	//thread_handler.queue();
}

void led_man_queue() {
	// manually queue animations for startup
  thread_handler.queue(new Animation_Simple_DeskWhitePurpleFade());
	//thread_handler.queue(new Animation_Static_DeskThirdDimAmbient());
	//thread_handler.queue(new Animation_Simple_Indiv_Rainbow(&desk1));
	//thread_handler.queue(new Animation_Simple_Indiv_Rainbow(&desk2));

	//thread_handler.queue(new Animation_Holiday_Halloween_WinAllHalloweenSparkle());

	//thread_handler.queue(new Animation_Seasonal_Winter_WindowSnow(&window1));
	//thread_handler.queue(new Animation_Seasonal_Winter_WindowSnow(&window3));

  thread_handler.queue(new Animation_Simple_Indiv_CalmPurpleFade(&window1));
  //thread_handler.queue(new Animation_Simple_Indiv_CalmPurpleFade(&window2));
  thread_handler.queue(new Animation_Simple_Indiv_CalmPurpleFade(&window3));

  //thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window1));
  thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window2));
  //thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window3));
}
