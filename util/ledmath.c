#ifndef LEDMATH_C_
#define LEDMATH_C_

/*!
	@file ledmath.c
  	@brief This file contains mathematical utility functions for dorm LEDs.<br/>
	<a target="_blank" href="https://www.desmos.com/calculator/evodsxrtjj">Calculated Brightness Curves</a>
*/

/* ~~~ Brightness Curves ~~~ */
/* Curve input to bias towards lower outputs to cause more noticeable changes in brightness */

/*!
	@brief Curve brightness input quadratically
	@param x input
	@return function output
*/
unsigned long int quadraticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.003921568627 * (double) pow(x, 2));
}

/*!
	@brief Curve brightness input cubically
	@param x input
	@return function output
*/
unsigned long int cubicBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0000153787005 * (double) pow(x, 3));
}

/*!
	@brief Curve brightness input quartically
	@param x input
	@return function output
*/
unsigned long int quarticBrightness(long unsigned int x) {
	return (unsigned long int) round(0.0000000603086294 * (double) pow(x, 4));
}

/*!
	@brief Curve brightness input by inverse 4.10612163x^{0.745}
	@param x input
	@return function output
*/
unsigned long int inverseFractional_0745_Brightness(long unsigned int x) {
	return (unsigned long int) round(4.1083529414 * (double) pow(x, 0.745));
}

/*!
	@brief Curve brightness input by inverse 12.444452145x^{0.545}
	@param x input
	@return function output
*/
unsigned long int inverseFractional_0545_Brightness(long unsigned int x) {
	return (unsigned long int) round(12.444452148 * (double) pow(x, 0.545));
}

#endif
