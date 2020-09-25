#pragma once

#ifndef MY_CONSOLE_INPUT_H

#define MY_CONSOLE_INPUT_H

#include <limits> 
#include <cmath>
#include <cfloat>  // for limits of a double DBL_MIN and DBL_MAX
//#include "MyConsoleInput.cpp"

class ConsoleInput
{
public:
	/**	ReadDouble function
	 * Reads a valid double value from the console with range checking
	 *
	 * @param  MIN the minimum value the user may enter; defaults to the maximum negative double.
	 * @param  MIN the minimum value the user may enter; defaults to the maximum double.
	 * @return A validated double input by the user.
	*/
	static double ReadDouble(const double MIN = std::numeric_limits<double>::min(), const double MAX = std::numeric_limits<double>::max());

	/**	ReadInteger function
	 * Reads a valid int value from the console with range checking
	 *
	 * @param  MIN the minimum value the user may enter; defaults to the minimum int.
	 * @param  MIN the minimum value the user may enter; defaults to the maximum int.
	 * @return A validated int input by the user.
	*/
	static int ReadInteger(const int MIN = INT_MIN, const int MAX = INT_MAX);

};
#endif // end of ifndef MY_CONSOLE_INPUT_H
