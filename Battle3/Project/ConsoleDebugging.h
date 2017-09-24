#pragma once
#include <iostream>
#include "Debugging.h"

/*
 * Concrete Debugging that sends string to the console
 */
class ConsoleDebugging : public Debugging
{
public:
	void Print(const char* string)
	{
		std::cout << string << std::endl;
	}
};