#pragma once
#include "Monster.h"

/*
 * Spawner represents a generic spawning event. It may
 * be attached to a particular object, spawing monsters
 * around said object, or it could be attached to a spell,
 * spawning a bunch of monsters in a small area, or it
 * could be attached to a dungeon which uses the spawner
 * and others like it to populate the the dungeon.
 * 
 * This is the class that benefits from the prototype pattern.
 */
class Spawner
{
private:
	Monster* templateMonster;
public:
	Spawner(Monster* templateMonster) : templateMonster(templateMonster)
	{
	}
	~Spawner()
	{
		//assumes the template monster is local to an enclosing scope
		//and that the lifetime is maintained appropriately by said
		//scope. Since templateMonster is local to a scope, it would
		//be inappropriate to delete it.
	}

	Monster* spawn() const
	{
		return templateMonster->clone();
	}
};