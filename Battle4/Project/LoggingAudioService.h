#pragma once
#include <ostream>
#include <map>
#include "Audio.h"

/*
 * LoggingAudioService prints when and what is playing
 * to the screen.
 */
class LoggingAudioService : public Audio
{
private:
	std::map<unsigned int, const char*> songNameMap;
	std::ostream& loggingTarget;

	Audio* next;
public:
	LoggingAudioService(std::ostream& loggingTarget, Audio* next) : loggingTarget(loggingTarget),
		next(next)
	{
	}
	~LoggingAudioService()
	{
	}

	//stores the provided audio within the service for later use
	int RegisterAudio(const char* filename)
	{
		int id = next->RegisterAudio(filename);
		songNameMap.insert(std::make_pair(id, filename));

		loggingTarget << "Song " << filename << " is registered with id " << id << std::endl;

		return id;
	}

	//starts playing a song
	void PlayAudio(int id)
	{
		std::map<unsigned int, const char*>::iterator itr = songNameMap.find(id);
		if (itr == songNameMap.end())
		{
			loggingTarget << "Song with id " << id << " requested to play but not found!" << std::endl;
		}
		else
		{
			loggingTarget << "Song " << itr->second << " with id " << id << " playing." << std::endl;
		}

		next->PlayAudio(id);
	}

	//pauses a song. calling play will start the song from where it left off
	void PauseAudio(int id)
	{
		std::map<unsigned int, const char*>::iterator itr = songNameMap.find(id);
		if (itr == songNameMap.end())
		{
			loggingTarget << "Song with id " << id << " requested to pause but not found!" << std::endl;
		}
		else
		{
			loggingTarget << "Song " << itr->second << " with id " << id << " paused." << std::endl;
		}

		next->PauseAudio(id);
	}

	//stops a song. calling play will start the song from the beginning
	void StopAudio(int id)
	{
		std::map<unsigned int, const char*>::iterator itr = songNameMap.find(id);
		if (itr == songNameMap.end())
		{
			loggingTarget << "Song with id " << id << " requested to stop but not found!" << std::endl;
		}
		else
		{
			loggingTarget << "Song " << itr->second << " with id " << id << " stopped." << std::endl;
		}

		next->StopAudio(id);
	}

	//stops all playing audio. calling play will start the selected song from the beginning
	void StopAllAudio()
	{
		loggingTarget << "Stopping all audio" << std::endl;

		next->StopAllAudio();
	}
};