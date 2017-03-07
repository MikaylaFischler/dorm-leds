#include "MSGEQ7.hpp"

// <<constructors>>
MSGEQ7::MSGEQ7(String name, int strobe_port, int reset_port, int input_port) : Device(name, DEV_MSGEQ7) {
	this->strobe = new DigitalDevice(name + F(": Strobe"), strobe_port, OUTPUT, DEV_GENERIC_D_OUTPUT);
	this->reset = new DigitalDevice(name + F(": Reset"), reset_port, OUTPUT, DEV_GENERIC_D_OUTPUT);
	this->input = new AnalogDevice(name + F(": Signal"), input_port, DEV_GENERIC_A_INPUT);
}

// <<destructor>>
MSGEQ7::~MSGEQ7() {
	delete this->strobe;
	delete this->reset;
	delete this->input;
}

// update stored values
void MSGEQ7::update(int value) {
	reset->write(HIGH);
	reset->write(LOW);

	for (int i = 0; i < 7; i++) {
		strobe->write(LOW);
		delay(30); // THIS IS A PROBLEM

		spectrum_values[i] =

		strobe->write(HIGH);
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
