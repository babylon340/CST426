#pragma once
#include "Monster.h"

/*
 * Ogre represents a more complex Monster.
 * Ogres have a particular coloring that, in more
 * complex versions, can indicate abilities.
 */
class Ogre : public Monster
{
private:
	const char* coloring;
public:
	Ogre(const char* coloring) : Monster(30),
		coloring(coloring)
	{
	}
	Ogre(const Ogre& o) : Monster(o),
		coloring(o.coloring)
	{
	}
	~Ogre()
	{
		//Assumes coloring is a static value and should not be deleted.
		//Means the copy constructor does not need to duplicate the
		//coloring string, but will leak memory if a dynamic string is
		//provided and all instances are destroyed.
	}

	const char* getColoring() const
	{
		return coloring;
	}

	Monster* clone() const
	{
		return new Ogre(*this);
	}
};