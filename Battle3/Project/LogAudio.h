#pragma once
#include <iostream>
#include "Audio.h"

/*
 * Outputs filename "played" to console
 */
class LogAudio : public Audio
{
public:
	void PlayAudio(const char* filename)
	{
		std::cout << "Playing song " << filename << std::endl;
	}
};