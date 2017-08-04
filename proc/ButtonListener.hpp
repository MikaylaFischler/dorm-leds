#ifndef BUTTON_LISTENER_HPP_
#define BUTTON_LISTENER_HPP_

#include <Arduino.h>
#include "Listener.hpp"

class ButtonListener : public Listener {
private:
	int last_state;
	bool state;
	bool triggered;
	bool invert;

	int (*read) (void);
public:
	ButtonListener(int (*buttonCheck) (void));
	ButtonListener(int (*buttonCheck) (void), bool invertButton);
	virtual ~ButtonListener() {}

	virtual void init();
	virtual void step();

	bool isPressed() const;
	bool wasPressed();
};

#endif
