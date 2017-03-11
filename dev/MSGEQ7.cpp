#include "MSGEQ7.hpp"

// <<constructor>>
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
	return map(spectrum_values[i], NOISE_FILTER, 1023, 0, 255);
}

// an overload of the [] operator to provide the 8-bit values
int MSGEQ7::operator[] (int index) const {
	return get8Bit(index);
}

/* ~~~ Process Sub-Class ~~~ */

// <<constructor>>
MSGEQ7::UpdaterProcess::UpdaterProcess(MSGEQ7* equalizer) {
	this->equalizer = equalizer;
}

// <<destructor>>
MSGEQ7::UpdaterProcess::~UpdaterProcess() {}

void MSGEQ7::UpdaterProcess::init() {
 	Process::init();
 	this->name = F("MSGEQ7 Device Status Updater");
    this->update_rate = 1;

	this->stack = new LocalStack();
	this->stack->push(new MemObj(new bool(true)));
	this->stack->push(new MemObj(new bool(false)));
	this->stack->push(new MemObj(new short int(0)));

	digitalWrite(equalizer->reset, HIGH);
	digitalWrite(equalizer->reset, LOW);
}

void MSGEQ7::UpdaterProcess::step() {
	bool& new_call = this->stack->get(0)->get<bool>();
	bool& waiting = this->stack->get(1)->get<bool>();
	short int& i = this->stack->get(2)->get<short int>();

	// is this a new call?
	if (new_call) {
		digitalWrite(equalizer->reset, HIGH);
		digitalWrite(equalizer->reset, LOW);
		new_call = false;
	}

	digitalWrite(equalizer->strobe, LOW);
	equalizer->spectrum_values[i] = analogRead(equalizer->input);
    equalizer->spectrum_values[i] = constrain(equalizer->spectrum_values[i], NOISE_FILTER, 1023);
	digitalWrite(equalizer->strobe, HIGH);

	if (i == 0) {
		// Serial.print(equalizer->spectrum_values[0]);
	} else {
		// Serial.print(F(" "));
		// Serial.print(equalizer->spectrum_values[i]);
	}

	i++;

	// check if read all frequencies
	if (i > 7) {
		// some of these SHOULD be already correct, but do them again to be safe
	    this->update_rate = 1;
		new_call = true;
		waiting = false;
		i = 0;

		// Serial.println("");
	}
}

void MSGEQ7::UpdaterProcess::clean() {
	this->stack->get(0)->destroy<bool>();
	this->stack->get(1)->destroy<bool>();
	this->stack->get(2)->destroy<short int>();

	delete this->stack;
}
