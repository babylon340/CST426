#pragma once

/*
 * Minimalist implementation of the Prototype pattern
 * through a generic Monster class.
 * clone() makes use of the copy constructor do its job.
 */
class Monster
{
private:
	float hp;
public:
	Monster(float hp) : hp(hp)
	{
	}
	Monster(const Monster& m) : hp(m.hp)
	{
	}
	virtual ~Monster() {}

	float getHP() const
	{
		return hp;
	}

	virtual Monster* clone() const = 0;
};