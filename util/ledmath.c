#ifndef LEDMATH_C_
#define LEDMATH_C_

/*
  Dorm LED Project: ledmath.c
  This file contains mathematical utility functions for dorm LEDs.

  Created by: Mikayla Fischler
  2017-03-11 @ WPI

  Calculated Brightness Curves: https://www.desmos.com/calculator/evodsxrtjj
*/

/* ~~~ Brightness Curves ~~~ */
/* Curve input to bias towards lower outputs to cause more noticeable changes in brightness */

// curve brightness input quadratically
unsigned long int quadraticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.003921568627 * (double) pow(x, 2));
}

// curve brightness input cubically
unsigned long int cubicBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0000153787005 * (double) pow(x, 3));
}

// curve brightness input quartically
unsigned long int quarticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0000000603086294 * (double) pow(x, 4));
}

// curve inverse 4.10612163x^{0.745}
unsigned long int inverseFractional_0745_Brightness(long unsigned int x) {
	return (unsigned long int) round(4.1083529414 * (double) pow(x, 0.745));
}

// curve inverse 12.444452145x^{0.545}
unsigned long int inverseFractional_0545_Brightness(long unsigned int x) {
	return (unsigned long int) round(12.444452148 * (double) pow(x, 0.545));
}

#endif
