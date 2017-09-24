#include <iostream>
#include <cstring>

#include "../Project/Monster.h"
#include "../Project/Goblin.h"
#include "../Project/GoblinMage.h"
#include "../Project/Drow.h"
#include "../Project/Ogre.h"
#include "../Project/Spawner.h"

const char* stringify(bool input);
template <typename Type>
bool AssertTypeOf(Monster* m);
bool AssertGoblinsOfDifferentTribes(Monster* m1, Monster* m2);
bool AssertGoblinAndDrowSameSpell(Monster* g, Monster* d);
bool AssertOgreColor(Monster* o, const char* color);

int main()
{
	std::cout << "Constructing template Monsters" << std::endl;

	//Goblins
	Goblin goblin_one("blood rage");
	Goblin goblin_two("fire wrath");

	//Goblin mages
	GoblinMage gMage_one("blood rage", "vampirism");
	GoblinMage gMage_two("fire wrath", "inferno");

	//Drows
	Drow drow_one("vampirism");
	Drow drow_two("inferno");

	//Ogres
	Ogre ogre_one("yellow");
	Ogre ogre_two("green");

	std::cout << "Constructing spawners" << std::endl;
	Spawner goblin_one_spawn(&goblin_one);
	Spawner goblin_two_spawn(&goblin_two);
	Spawner gMage_one_spawn(&gMage_one);
	Spawner gMage_two_spawn(&gMage_two);
	Spawner drow_one_spawn(&drow_one);
	Spawner drow_two_spawn(&drow_two);
	Spawner ogre_one_spawn(&ogre_one);
	Spawner ogre_two_spawn(&ogre_two);

	std::cout << "Generating clones to test with" << std::endl;
	Monster* g1 = goblin_one_spawn.spawn();
	Monster* g2 = goblin_two_spawn.spawn();
	Monster* gm1 = gMage_one_spawn.spawn();
	Monster* gm2 = gMage_two_spawn.spawn();
	Monster* d1 = drow_one_spawn.spawn();
	Monster* d2 = drow_two_spawn.spawn();
	Monster* o1 = ogre_one_spawn.spawn();
	Monster* o2 = ogre_two_spawn.spawn();

	std::cout << "Assert that the goblin spawner is spawning goblins" << std::endl;
	std::cout << stringify(AssertTypeOf<Goblin>(g1)) << std::endl;

	std::cout << "Assert that the goblins spawned are of different tribes" << std::endl;
	std::cout << stringify(AssertGoblinsOfDifferentTribes(g1, g2)) << std::endl;

	std::cout << "Assert that goblins and drow are different" << std::endl;
	std::cout << stringify(!AssertTypeOf<Goblin>(d1)) << std::endl;

	std::cout << "Assert that goblin mage two and drow two have the same spell" << std::endl;
	std::cout << stringify(AssertGoblinAndDrowSameSpell(gm2, d2)) << std::endl;

	std::cout << "Assert that ogre one is yellow" << std::endl;
	std::cout << stringify(AssertOgreColor(o1, "yellow")) << std::endl;

	system("pause");
	return 0; 
}

const char* stringify(bool input)
{
	return input ? "True" : "False";
}

template <typename Type>
bool AssertTypeOf(Monster* m)
{
	return dynamic_cast<Type*>(m) != nullptr;
}

bool AssertGoblinsOfDifferentTribes(Monster* m1, Monster* m2)
{
	Goblin* g1 = dynamic_cast<Goblin*>(m1);
	Goblin* g2 = dynamic_cast<Goblin*>(m2);

	if (g1 == nullptr || g2 == nullptr)
	{
		return false;
	}

	return strcmp(g1->getTribe(), g2->getTribe()) != 0;
}

bool AssertGoblinAndDrowSameSpell(Monster* g, Monster* d)
{
	GoblinMage* gm = dynamic_cast<GoblinMage*>(g);
	Drow* dr = dynamic_cast<Drow*>(d);

	if (gm == nullptr || dr == nullptr)
	{
		return false;
	}

	return strcmp(gm->getSpell(), dr->getSpell()) == 0;
}

bool AssertOgreColor(Monster* o, const char* color)
{
	Ogre* og = dynamic_cast<Ogre*>(o);

	if (og == nullptr)
	{
		return false;
	}

	return strcmp(og->getColoring(), color) == 0;
}