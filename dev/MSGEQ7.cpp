#include "MSGEQ7.hpp"

// <<constructor>>
MSGEQ7::MSGEQ7(String name, int strobe_port, int reset_port, int input_port) : Device(name, DEV_MSGEQ7),
				strobe(strobe_port), reset(reset_port), input(input_port) {
	pinMode(strobe_port, OUTPUT);
	pinMode(reset_port, OUTPUT);
}

// <<destructor>>
MSGEQ7::~MSGEQ7() {}

// get the value (NOISE_FILTER to 1023), note: there is some signal noise when there is silence
int MSGEQ7::getRaw(int i) const { return spectrum_values[i]; }

// get the value (0 to 255)
int MSGEQ7::get8Bit(int i) const {
	// mapped to 8-bit, constrain the noise out (make it all 0)
	return map(spectrum_values[i], NOISE_FILTER, 1023, 0, 255);
}

// get the value (0 to 80 to be in range of a window strip)
int MSGEQ7::getInWindowRange(int i) const {
	return map(spectrum_values[i], NOISE_FILTER, 1023, 0, 80);
}

// an overload of the [] operator to provide the 8-bit values
int MSGEQ7::operator[] (int index) const { return get8Bit(index); }

/* ~~~ Process Sub-Class ~~~ */

// <<constructor>>
MSGEQ7::UpdaterProcess::UpdaterProcess(MSGEQ7* eq) {
	this->equalizer = eq;
}

// <<destructor>>
MSGEQ7::UpdaterProcess::~UpdaterProcess() {}

void MSGEQ7::UpdaterProcess::init() {
 	Process::init();
 	this->name = F("MSGEQ7 Device Status Updater");
    this->update_rate = 1;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new short int(0)));

	digitalWrite(equalizer->reset, HIGH);
	digitalWrite(equalizer->reset, LOW);
}

void MSGEQ7::UpdaterProcess::step() {
	short int& i = this->stack->get(0)->get<short int>();

	// is this a new call?
	if (i == 0) {
		digitalWrite(equalizer->reset, HIGH);
		digitalWrite(equalizer->reset, LOW);
	}

	digitalWrite(equalizer->strobe, LOW);
    equalizer->spectrum_values[i] = constrain(analogRead(equalizer->input), NOISE_FILTER, 1023);
	digitalWrite(equalizer->strobe, HIGH);

	// if (i == 0) {
	// 	Serial.print(equalizer->spectrum_values[0]);
	// } else {
	// 	Serial.print(F(" "));
	// 	Serial.print(equalizer->spectrum_values[i]);
	// }

	// check if read all frequencies
	if (++i > 7) { i = 0; }
	// if (i == 0) { Serial.println(""); }
}

void MSGEQ7::UpdaterProcess::clean() {
	this->stack->get(0)->destroy<short int>();

	delete this->stack;
}
