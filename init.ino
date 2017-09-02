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
	// create strips

	// old strips
	// npsm.addStrip(F("Window 1"), false, new Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_CL, STRIP_TYPE_RGBW));
	// npsm.addStrip(F("Window 2"), false, new Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_CR, STRIP_TYPE_RGBW));
	// npsm.addStrip(F("Window 3"), false, new Adafruit_NeoPixel(WINDOW_LENGTH, STRIP_PIN_W1, STRIP_TYPE_RGB));
	//
	// npsm.addStrip(F("Desk 1"), false, new Adafruit_NeoPixel(DESK1_LENGTH, STRIP_PIN_W2, STRIP_TYPE_RGB));
	// npsm.addStrip(F("Desk 2"), false, new Adafruit_NeoPixel(DESK2_LENGTH, STRIP_PIN_W3, STRIP_TYPE_RGB));

	// current strips
	npsm.addStrip(F("Ceiling Left"), true, new Adafruit_NeoPixel(CEILING_LEFT_LENGTH, STRIP_PIN_CL, STRIP_TYPE_RGBW));
	npsm.addStrip(F("Ceiling Right"), true, new Adafruit_NeoPixel(CEILING_RIGHT_LENGTH, STRIP_PIN_CR, STRIP_TYPE_RGBW));

	npsm.addStrip(F("Window 1"), false, new Adafruit_NeoPixel(WINDOW_A_LENGTH, STRIP_PIN_W1, STRIP_TYPE_RGB));
	npsm.addStrip(F("Window 2"), false, new Adafruit_NeoPixel(WINDOW_B_LENGTH, STRIP_PIN_W2, STRIP_TYPE_RGB));
	npsm.addStrip(F("Window 3"), false, new Adafruit_NeoPixel(WINDOW_B_LENGTH, STRIP_PIN_W3, STRIP_TYPE_RGB));

	// begin() the strips
	for (int i = 0; i < npsm.numStrips(); i++) {
		npsm[i]->begin();
		npsm[i]->show();
	}
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
	// pulse monitor
	device_manager.mount(new PulseMonitor(F("Pulse Monitor"), PULSESENSOR_INPUT));					// 2
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
	// thread_handler.queue(new Animation_Static_Indiv_ThirdDimAmbient(ID_CEILING_LEFT));
	// thread_handler.queue(new Animation_Static_Indiv_ThirdDimAmbient(ID_CEILING_RIGHT));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowWhiteTheaterChase(ID_CEILING_LEFT));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowWhiteTheaterChase(ID_CEILING_RIGHT));
	thread_handler.queue(new Animation_Advanced_Pulse_CeilingChart());

	// thread_handler.queue(new Animation_Holiday_Halloween_WinAllHalloweenSparkle());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(ID_WINDOW_1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(ID_WINDOW_2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowSnow(ID_WINDOW_3));

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(ID_WINDOW_1));
	// thread_handler.queue(new Animation_Simple_Indiv_CalmPurpleFade(ID_WINDOW_2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowRain(ID_WINDOW_3));

	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(ID_WINDOW_1));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(ID_WINDOW_2));
	// thread_handler.queue(new Animation_Simple_Indiv_RainbowCycle(ID_WINDOW_3));

	// thread_handler.queue(new Animation_Advanced_Audio_BasePulseCircularEqWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_MaxEqualizerWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassMidPulseWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassPulseMidHueWindow());
	// thread_handler.queue(new Animation_Advanced_Audio_BassPulseWindow());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_ColorWipe(ID_WINDOW_1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_WindowColors(ID_WINDOW_2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Spring_ColorWipe(ID_WINDOW_3));

	// thread_handler.queue(new Animation_Static_TransFlagWindows());
	// thread_handler.queue(new Animation_Static_TransFlagStripedWindows());

	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(ID_WINDOW_1));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(ID_WINDOW_2));
	// thread_handler.queue(new Animation_Seasonal_Indiv_Weather_WindowLightRain(ID_WINDOW_3));

	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(ID_WINDOW_1, COLOR_BLUE));
	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(ID_WINDOW_2, COLOR_GREEN));
	// thread_handler.queue(new Animation_Simple_Indiv_ColorFade(ID_WINDOW_3, COLOR_BLUE));
}
