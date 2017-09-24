#pragma once
#include "Monster.h"

/*
 * Goblin represents a more complex type of Monster.
 * Goblins can belong to a particular tribe.
 */
class Goblin : public Monster
{
private:
	const char* tribe;
public:
	Goblin(const char* tribe) : Monster(10),
		tribe(tribe)
	{
	}
	Goblin(const Goblin& g) : Monster(g),
		tribe(g.tribe)
	{
	}
	~Goblin()
	{
		//Assumes tribe is a static value and should not be deleted.
		//Means the copy constructor does not need to duplicate the
		//tribe string, but will leak memory if a dynamic string is
		//provided and all instances are destroyed.
	}

	const char* getTribe() const
	{
		return tribe;
	}

	Monster* clone() const
	{
		return new Goblin(*this);
	}
};