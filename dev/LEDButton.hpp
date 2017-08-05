#ifndef LEDBUTTON_HPP_
#define LEDBUTTON_HPP_

/*
 *	Device code for sparkfun LED button
 *  Really simple, its just an LED and a button in one
 */

#include "../lib/device/Device.hpp"

class LEDButton : public Device {
private:
	const int led;
	const int button;
public:
	LEDButton(String name, int port_led, int port_button);
	virtual ~LEDButton();

	void setLED(int value);
	int read() const;
};

#endif
