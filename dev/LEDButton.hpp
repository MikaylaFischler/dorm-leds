#ifndef LEDBUTTON_HPP_
#define LEDBUTTON_HPP_

#include "../lib/Device.hpp"
#include "DigitalDevice.hpp"

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
