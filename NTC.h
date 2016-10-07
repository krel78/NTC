/*
	Copyright (c) 2016 by Leszek Krehut

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/

/*
@brief Class for calculating temperature of NTC.
@details Performs calculation of the resistance of NTC resistor, basing on ADC input value
	The circuit must look as follows:

	 AREF -----+   		 
		       |  		 
		      | |            		 
		      | | Rref       		 
		      | |           		 
		       |             		 
		       +------  AI (ADC input)
		       |    
		      | ||
		      |/| NTC
		     || |
		       |   
	GND -------+------

	Measured resistance is converted to the temperature according to logarythmic expression:

	T = [ 1 / [ A1 + B1 * log(Rntc / R25) + C1 * (log(Rntc / R25))^2 + D1 * (log(Rntc / R25))^3 ]] - 273.15

	Result is given in Celsius degrees.

	Assuming ADC gives 10-bit result - single ended

@param APin
	Number of analog input of Arduino/Genuino board
@param RRef
	Reference resistance value in Ohms
@param R25
	Characeristic resistance of NTC for 25 Celsius degrees reference temperature 
@param A1, B1, C1, D1
	Parameters of logarythmic expression for temperature calculation
@par Example
@code
	NTC TempToMeasure(A0, 4700, 4700, 3.354016e-3, 2.569355e-4, 2.626311e-6, 0.675278e-7);
	double Readout = TempToMeasure.Temperature();
@endcode
*/

#ifndef NTC_h
#define NTC_h

#include "Arduino.h"

class NTC
{
	public:
		NTC(int pin, double RRef, double R25, double NTC_A1, double NTC_B1, double NTC_C1, double NTC_D1);
		double Temperature();
	private:
		int _APin;
		double _RRef;
		double _NTC_R25;
		double _NTC_A1;
		double _NTC_B1;
		double _NTC_C1;
		double _NTC_D1;
};

#endif /*NTC_h*/
