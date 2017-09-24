#include <iostream>
#include <string>

#include "../Project/LogAudio.h"
#include "../Project/LogRenderer.h"
#include "../Project/ConsoleDebugging.h"
#include "../Project/ServiceLocator.h"
#include "../Project/Spell.h"

/////////////////////////////
// Some test spell classes //
//    for playing with     //
/////////////////////////////

class Fireball : public Spell
{
private:
	unsigned int audioEffectId;
	unsigned int imageEffectId;
public:
	Fireball() : audioEffectId(RegisterAudio("fireball.mp3")),
		imageEffectId(RegisterImage("fireEffect.png"))
	{
	}

	void Use()
	{
		std::string imageId = "Fireball image id: " + std::to_string(imageEffectId);

		PlayAudio(audioEffectId);
		DrawImage(imageEffectId);
		DebugString(imageId.c_str());
	}
};

class Inferno : public Spell
{
private:
	unsigned int audioEffectId;
	unsigned int imageEffectId;
public:
	Inferno() : audioEffectId(RegisterAudio("inferno.mp3")),
		imageEffectId(RegisterImage("fireEffect.png"))
	{
	}

	void Use()
	{
		std::string imageId = "Inferno image id: " + std::to_string(imageEffectId);

		PlayAudio(audioEffectId);
		DrawImage(imageEffectId);
		DebugString(imageId.c_str());
	}
};

class ChainLightning : public Spell
{
private:
	unsigned int audioEffectId;
	unsigned int imageEffectId;
public:
	ChainLightning() : audioEffectId(RegisterAudio("lightning.mp3")),
		imageEffectId(RegisterImage("lightning.png"))
	{
	}

	void Use()
	{
		std::string imageId = "Chain Lightning image id: " + std::to_string(imageEffectId);

		PlayAudio(audioEffectId);
		DrawImage(imageEffectId);
		DebugString(imageId.c_str());
	}
};

class Vampirism : public Spell
{
private:
	unsigned int audioEffectId;
	unsigned int imageEffectId;
public:
	Vampirism() : audioEffectId(RegisterAudio("vampireSpell.mp3")),
		imageEffectId(RegisterImage("drainEffect.png"))
	{
	}

	void Use()
	{
		std::string imageId = "Vampirism image id: " + std::to_string(imageEffectId);

		PlayAudio(audioEffectId);
		DrawImage(imageEffectId);
		DebugString(imageId.c_str());
	}
};

/////////////////////
// End test spells //
/////////////////////

int main()
{
	std::cout << "Initializing service locator" << std::endl;
	ServiceLocator::Service()->SetAudio(new LogAudio());
	ServiceLocator::Service()->SetRenderer(new LogRenderer());
	ServiceLocator::Service()->SetDebugging(new ConsoleDebugging());

	std::cout << "Initializing derived spell classes" << std::endl;
	std::cout << "Note: fireball and inferno should have the same image id" << std::endl << std::endl;
	Fireball fireball_one;
	Inferno inferno;
	Fireball fireball_two;
	ChainLightning lightning;
	Vampirism vampirism;

	std::cout << "Use fireball!" << std::endl;
	fireball_one.Use();

	std::cout << std::endl << "Use inferno!" << std::endl;
	inferno.Use();

	std::cout << std::endl << "Use other fireball!" << std::endl;
	fireball_two.Use();

	std::cout << std::endl << "Use chain lightning!" << std::endl;
	lightning.Use();

	std::cout << std::endl << "Use vampirism!" << std::endl;
	vampirism.Use();

	system("pause");
	return 0;
}