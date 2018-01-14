#ifndef MSGEQ7_HPP_
#define MSGEQ7_HPP_

/*
 *	Device code for MSGEQ7 IC
 *  Requires a process for parralized updating
 *  63Hz, 160Hz, 400Hz, 1kHz, 2.5kHz, 6.25kHz and 16kHz
 */

#include "../lib/device/Device.hpp"
#include "../lib/exe/Process.hpp"

class MSGEQ7 : public Device {
private:
	// control for chip
	const int strobe;
	const int reset;
	const int input;

	int spectrum_values[7];				// all frequency range data

	static const int NOISE_FILTER = 94;	// noise filter threshold (recommended: 80)
public:
	MSGEQ7(String name, int strobe_port, int reset_port, int input_port);
	virtual ~MSGEQ7() {}

	int getRaw(int i) const;
	int get8Bit(int i) const;
	int getInRange(int i, int min, int max) const;

	int operator[] (int index) const;

	// note: this process has variable update rates
	friend class UpdaterProcess;
	class UpdaterProcess : public Process {
	private:
		short int cur_freq;	// current frequency range
		MSGEQ7* equalizer; 	// do NOT call delete on this in this class
	public:
		UpdaterProcess(MSGEQ7* eq) : cur_freq(0), equalizer(eq) {}
		~UpdaterProcess() {}

		void init();
		void step();
	};
};

#endif
