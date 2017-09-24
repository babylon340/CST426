#pragma once

/*
 * Debugging is a service provided by the service locator
 * which allows arbitrary text strings to be printed to
 * some target.
 */
class Debugging
{
public:
	virtual ~Debugging() {}

	virtual void Print(const char* string) = 0;
};