#ifndef MSGEQ7_HPP_
#define MSGEQ7_HPP_

/*
 *	Device code for MSGEQ7 IC
 *  Requires a process for parralized updating
 *  63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz and 16kHz
 */

#include "../lib/Device.hpp"
#include "../lib/Process.hpp"

class MSGEQ7 : public Device {
private:
	const int strobe;
	const int reset;
	const int input;

	int spectrum_values[7];

	static const int NOISE_FILTER = 80;
public:
	MSGEQ7(String name, int strobe_port, int reset_port, int input_port);
	virtual ~MSGEQ7();

	int getRaw(int i) const;
	int get8Bit(int i) const;
	int getInWindowRange(int i) const;

	int operator[] (int index) const;

	// note: this process has variable update rates
	friend class UpdaterProcess;
	class UpdaterProcess : public Process {
	private:
		MSGEQ7* equalizer; // do not call delete on this
	public:
		UpdaterProcess(MSGEQ7* eq);
		virtual ~UpdaterProcess();

		void init();
		void step();
		void clean();
	};
};

#endif
