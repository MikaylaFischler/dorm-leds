/*
  Dorm LED Project: init.ino
  This file contains the initialization code for the dorm LED system.

  Created by: Mikayla Fischler
  9/30/2016 @ WPI
*/

void set_pin_modes() {
	// set pin modes here

}

void init_strips() {
	// Create Strips
	npsm.addStrip(new Adafruit_NeoPixel(CEILING_LEFT_LENGTH, STRIP_PIN_CL, STRIP_TYPE_RGBW));
	npsm.addStrip(new Adafruit_NeoPixel(CEILING_RIGHT_LENGTH, STRIP_PIN_CR, STRIP_TYPE_RGBW));

	npsm.addStrip(new Adafruit_NeoPixel(WINDOW_A_LENGTH, STRIP_PIN_W1, STRIP_TYPE_RGB));
	npsm.addStrip(new Adafruit_NeoPixel(WINDOW_B_LENGTH, STRIP_PIN_W2, STRIP_TYPE_RGB));
	npsm.addStrip(new Adafruit_NeoPixel(WINDOW_B_LENGTH, STRIP_PIN_W3, STRIP_TYPE_RGB));

	// begin() the Strips
	for (int i = 0; i < npsm.numStrips(); i++) {
		npsm[i]->begin();
		npsm[i]->show();
	}
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
	thread_handler.queue(new MSGEQ7::UpdaterProcess(device_manager.getDevice<MSGEQ7>(1)));

	// system processes
	//thread_handler.queue();
}

void led_man_queue() {
	// manually queue animations for startup

	// thread_handler.queue(new Animation_Simple_DeskWhitePurpleFade());
	thread_handler.queue(new Animation_Static_Indiv_ThirdDimAmbient(&desk1));
	thread_handler.queue(new Animation_Static_Indiv_ThirdDimAmbient(&desk2));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&desk1));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&desk2));

	// thread_handler.queue(new Animation_Holiday_Halloween_WinAllHalloweenSparkle());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(&window1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(&window2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(&window3));

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(&window1));
	// thread_handler.queue(new Animation_Simple_Indiv_CalmPurpleFade(&window2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowRain(&window3));

	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window1));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window2));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(&window3));

	thread_handler.queue(new Animation_Advanced_Audio_BasePulseCircularEqWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_MaxEqualizerWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassMidPulseWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassPulseMidHueWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassPulseWindow());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_ColorWipe(&window1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_WindowColors(&window2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_ColorWipe(&window3));

	// thread_handler.queue(new Animation_Static_TransFlagWindows());
	// thread_handler.queue(new Animation_Static_TransFlagStripedWindows());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(&window1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(&window2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(&window3));

	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(&window1, COLOR_BLUE));
	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(&window2, COLOR_GREEN));
	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(&window3, COLOR_BLUE));
}
