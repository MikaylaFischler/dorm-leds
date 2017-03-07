#ifndef MSGEQ7_HPP_
#define MSGEQ7_HPP_

#include "../lib/Device.hpp"

class MSGEQ7 : public Device {
private:
	const int strobe;
	const int reset;
	const int input;

	int spectrum_values[7];

	static const int NOISE_FILTER = 0;
public:
	MSGEQ7(String name, int strobe_port, int reset_port, int input_port);
	virtual ~MSGEQ7();

	void update();
	int getRaw(int i) const;
	int get8Bit(int i) const;

	int operator[] (int index) const;
};

#endif
