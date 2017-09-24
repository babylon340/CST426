#pragma once
#include "Audio.h"
#include "Renderer.h"
#include "Debugging.h"

/*
 * Simple service locator for use by the subclass sandbox.
 * Battle4 will also make use of the service locator as its
 * inteded pattern.
 */
class ServiceLocator
{
private:
	Audio* audioService;
	Renderer* renderService;
	Debugging* debuggingService;

	ServiceLocator() {}
	ServiceLocator(const ServiceLocator& sl) = delete;
public:
	~ServiceLocator() {}

	void SetAudio(Audio* audio)
	{
		audioService = audio;
	}
	Audio* GetAudio()
	{
		return audioService;
	}

	void SetRenderer(Renderer* renderer)
	{
		renderService = renderer;
	}
	Renderer* GetRenderer()
	{
		return renderService;
	}

	void SetDebugging(Debugging* debugger)
	{
		debuggingService = debugger;
	}
	Debugging* GetDebugging()
	{
		return debuggingService;
	}

	static ServiceLocator* Service()
	{
		static ServiceLocator service;
		return &service;
	}
};