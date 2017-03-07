#include "MSGEQ7.hpp"

// <<constructors>>
MSGEQ7::MSGEQ7(String name, int strobe_port, int reset_port, int input_port) : Device(name, DEV_MSGEQ7),
						strobe(strobe_port), reset(reset_port), input(input_port) {
	pinMode(strobe_port, OUTPUT);
	pinMode(reset_port, OUTPUT);
}

// <<destructor>>
MSGEQ7::~MSGEQ7() {}

// update stored values
void MSGEQ7::update() {
	digitalWrite(reset, HIGH);
	digitalWrite(reset, LOW);

	for (int i = 0; i < 7; i++) {
		digitalWrite(strobe, LOW);
		delay(30); // THIS IS A PROBLEM

		spectrum_values[i] = analogRead(input);

		digitalWrite(strobe, HIGH);
	}
}

// get the value (0 - 1023), note: there is some signal noise when there is silence
int MSGEQ7::getRaw(int i) const {
	return spectrum_values[i];
}

// get the value (0 - 255)
int MSGEQ7::get8Bit(int i) const {
	// mapped to 8-bit, constrain the noise out (make it all 0)
	return map(constrain(spectrum_values[i], NOISE_FILTER, 1023), NOISE_FILTER, 1023, 0, 255);
}

// an overload of the [] operator to provide the 8-bit values
int MSGEQ7::operator[] (int index) const {
	return get8Bit(index);
}
