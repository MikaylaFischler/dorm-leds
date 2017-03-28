#include "Animation_Seasonal.hpp"

/* ~~~ Generic Seasonal ~~~ */

// define the generic seasonal init
void Animation_Seasonal::init() {
  	Animation::init();
  	this->max_exec = -1;
}

/* ~~~ Generic Seasonal Individual ~~~ */
/* this is implemented differently here; no indiv file */

// define the generic seasonal individual init
void Animation_Seasonal_Indiv::init() {
  	Animation_Seasonal::init();
  	this->num_strips = 1;
}
