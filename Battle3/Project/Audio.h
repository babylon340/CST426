#pragma once

/*
 * Audio interface for use with serivce locator
 */
class Audio
{
public:
	virtual ~Audio() {}

	virtual void PlayAudio(const char* filename) = 0;
};