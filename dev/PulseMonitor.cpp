#include "PulseMonitor.hpp"

// check if the value of the pulse monitor passed the threshold indicating a heartbeat
bool PulseMonitor::beat() const { return analogRead(data_port) > PULSE_THRESHOLD; }

// return the value of the pulse sensor
int PulseMonitor::read() const { return analogRead(data_port); }
