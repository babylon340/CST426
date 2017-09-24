#pragma once
#include "Goblin.h"

/*
 * Goblin Mage is a more complex Goblin, able to cast spells like a Drow.
 */
class GoblinMage : public Goblin
{
private:
	const char* spell;
public:
	GoblinMage(const char* tribe, const char* spell) : Goblin(tribe),
		spell(spell)
	{
	}
	GoblinMage(const GoblinMage& gm) : Goblin(gm),
		spell(gm.spell)
	{
	}
	~GoblinMage()
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
		return new GoblinMage(*this);
	}
};