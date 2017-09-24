#pragma once
#include <map>
#include "ServiceLocator.h"

/*
 * Mapping provides a clean way for the Spell class to
 * remember previously registered resources.
 */
class Mapping
{
private:
	std::map<const char*, unsigned int> resourceToId;
	std::map<unsigned int, const char*> idToResource;
	unsigned int maxId;
public:
	Mapping() : maxId(0)
	{
	}

	unsigned int Map(const char* resource)
	{
		std::map<const char*, unsigned int>::iterator itr = resourceToId.find(resource);
		if (itr == resourceToId.end())
		{
			unsigned int id = maxId++;
			resourceToId.insert(std::make_pair(resource, id));
			idToResource.insert(std::make_pair(id, resource));
			return id;
		}
		return itr->second;
	}
	const char* Map(unsigned int id)
	{
		std::map<unsigned int, const char*>::iterator itr = idToResource.find(id);
		if(itr == idToResource.end())
		{
			return "Resource not found!";
		}
		return itr->second;
	}
};

/*
 * The Spell class implements the subclass sandbox by
 * providing the ability to register resources and use
 * them via inherited methods which are, themselves,
 * coupled to various engine subsystems.
 */
class Spell
{
private:
	static Mapping audioResource;
	static Mapping imageResource;
public:
	static int RegisterAudio(const char* filename)
	{
		return audioResource.Map(filename);
	}
	static int RegisterImage(const char* filename)
	{
		return imageResource.Map(filename);
	}
	static void PlayAudio(unsigned int id)
	{
		const char* audio = audioResource.Map(id);
		ServiceLocator::Service()->GetAudio()->PlayAudio(audio);
	}
	static void DrawImage(unsigned int id)
	{
		const char* image = imageResource.Map(id);
		ServiceLocator::Service()->GetRenderer()->Render(image);
	}
	static void DebugString(const char* string)
	{
		ServiceLocator::Service()->GetDebugging()->Print(string);
	}

	virtual void Use() = 0;
};

Mapping Spell::audioResource;
Mapping Spell::imageResource;