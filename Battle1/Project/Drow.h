#pragma once
#include "Monster.h"

/*
 * Drow represents a more complex type of Monster.
 * Drows can cast a particular spell.
 */
class Drow : public Monster
{
private:
	const char* spell;
public:
	Drow(const char* spell) : Monster(15),
		spell(spell)
	{
	}
	Drow(const Drow& d) : Monster(d),
		spell(d.spell)
	{
	}
	~Drow()
	{
		//Assumes spell is a static value and should not be deleted.
		//Means the copy constructor does not need to duplicate the
		//spell string, but will leak memory if a dynamic string is
		//provided and all instances are destroyed.
	}

	const char* getSpell() const
	{
		return spell;
	}

	Monster* clone() const
	{
		return new Drow(*this);
	}
};