#include "Listener.hpp"

// <<constructor>>
Listener::Listener() {}

// <<destructor>>
Listener::~Listener() { clean(); }

// basic initialization (have listeners update at 5 ms)
void Listener::init() { this->update_rate = 5; }
