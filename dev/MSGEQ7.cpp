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

// TODO this should NOT be here
// get the value (0 to 80 to be in range of a window strip)
int MSGEQ7::getInWindowRange(int i) const {
	return map(spectrum_values[i], NOISE_FILTER, 1023, 0, 80);
}

// an overload of the [] operator to provide the 8-bit values
int MSGEQ7::operator[] (int index) const { return get8Bit(index); }

/* ~~~ Process Sub-Class ~~~ */

void MSGEQ7::UpdaterProcess::init() {
 	Process::init();
 	this->name = F("MSGEQ7 Device Status Updater");
    this->update_rate = 1;

	digitalWrite(equalizer->reset, HIGH);
	digitalWrite(equalizer->reset, LOW);
}

void MSGEQ7::UpdaterProcess::step() {
	// is this a new call?
	if (cur_freq == 0) {
		digitalWrite(equalizer->reset, HIGH);
		digitalWrite(equalizer->reset, LOW);
	}

	digitalWrite(equalizer->strobe, LOW);
    equalizer->spectrum_values[cur_freq] = constrain(analogRead(equalizer->input), NOISE_FILTER, 1023);
	digitalWrite(equalizer->strobe, HIGH);

	// if (cur_freq == 0) {
	// 	Serial.print(equalizer->spectrum_values[0]);
	// } else {
	// 	Serial.print(F(" "));
	// 	Serial.print(equalizer->spectrum_values[cur_freq]);
	// }

	// check if read all frequencies
	if (++cur_freq > 7) { cur_freq = 0; }

	// if (cur_freq == 0) { Serial.println(""); }
}
