# NTC
Class for temperature measurement using NTC resistors (thermistors) connected to Arduino/Genuino analog inputs.

The circuit must look as follows:

	 AREF -----+   		 
		       |  		 
		      | |            		 
		      | | RRef       		 
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


Example of use:

We will use here analog input A0.

Reference resistor is 10kOhm which means RRef=10000.

NTC resistor is 4.7kOhm @ 25 Cdeg which means R25=4700

NTC parameters are: A1=3.354016e-3, B1=2.569355e-4, C1=2.626311e-6, D1=0.675278e-7

	NTC TempToMeasure(A0, 10000, 4700, 3.354016e-3, 2.569355e-4, 2.626311e-6, 0.675278e-7);
	double Readout = TempToMeasure.Temperature();

