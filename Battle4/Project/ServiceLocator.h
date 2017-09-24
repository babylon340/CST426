#pragma once
#include "Audio.h"
#include "NullAudio.h"

/*
 * ServiceLocator serves as a singleton service locator
 * that will provide global access to an audio interface.
 */
class ServiceLocator
{
private:
	Audio* audioService;
	Audio* nullAudioService;

	ServiceLocator() : audioService(nullptr),
		nullAudioService(new NullAudio)
	{
	}
	ServiceLocator(const ServiceLocator& sl) = delete;
public:
	~ServiceLocator()
	{
		if (audioService)
		{
			delete audioService;
		}
		delete nullAudioService;
	}

	//returns the previous audio service if it isn't used
	//in an audio chain and, consequently, needs to be deleted
	Audio* SetAudioService(Audio* service)
	{
		Audio* temp = audioService;
		audioService = service;
		return temp;
	}
	Audio* GetAudioService()
	{
		return audioService ? audioService : nullAudioService;
	}

	static ServiceLocator* Service()
	{
		static ServiceLocator service;
		return &service;
	}
};