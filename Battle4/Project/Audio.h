#pragma once

/*
 * Audio provides the abstract interface for an audio system.
 * It is provided by the ServiceLocator class.
 */
class Audio
{
public:
	virtual ~Audio() {}

	//stores the provided audio within the service for later use
	virtual int RegisterAudio(const char* filename) = 0;

	//starts playing a song
	virtual void PlayAudio(int id) = 0;

	//pauses a song. calling play will start the song from where it left off
	virtual void PauseAudio(int id) = 0;

	//stops a song. calling play will start the song from the beginning
	virtual void StopAudio(int id) = 0;

	//stops all playing audio. calling play will start the selected song from the beginning
	virtual void StopAllAudio() = 0;
};