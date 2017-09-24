#pragma once
#include "Audio.h"

/*
 * NullAudio implements the Audio interface but does nothing
 * with the provided input. As such, songs registered with the
 * NullAudio cannot be played with other Audio interfaces.
 */
class NullAudio : public Audio
{
private:
	unsigned int maxId;
public:
	NullAudio() : maxId(0)
	{
	}

	//stores the provided audio within the service for later use
	int RegisterAudio(const char* filename)
	{
		return maxId++;
	}

	//starts playing a song
	void PlayAudio(int id)
	{
	}

	//pauses a song. calling play will start the song from where it left off
	void PauseAudio(int id)
	{
	}

	//stops a song. calling play will start the song from the beginning
	void StopAudio(int id)
	{
	}

	//stops all playing audio. calling play will start the selected song from the beginning
	void StopAllAudio()
	{
	}
};