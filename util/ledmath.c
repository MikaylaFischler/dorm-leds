#ifndef LEDMATH_C_
#define LEDMATH_C_

/*
  Dorm LED Project: ledmath.c
  This file contains mathematical utility functions for dorm LEDs.

  Created by: Michael Fischler
  2017-03-11 @ WPI

  Calculated Brightness Curves: https://www.desmos.com/calculator/xqhb9ecn01
*/

/* ~~~ Brightness Curves ~~~ */
/* Curve input to bias towards lower outputs to cause more noticeable changes in brightness */

// curve brightness input quadratically
unsigned long int quadraticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0039215686 * (double) pow(x, 2));
}

// curve brightness input cubically
unsigned long int cubicBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0000153786 * (double) pow(x, 3));
}

// curve brightness input quartically
unsigned long int quarticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.000000060308 * (double) pow(x, 4));
}

#endif
