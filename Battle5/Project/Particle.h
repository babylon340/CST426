#pragma once
#include "Vector.h"

/*
 * A basic particle class, for demonstration purposes only.
 */
struct Particle
{
	Vector pos;
	Vector dir;
	float lifetime;

	Particle()
	{
	}
	Particle(Vector pos, Vector dir, float lifetime) : pos(pos),
		dir(dir), lifetime(lifetime)
	{
	}

	bool Update()
	{
		pos += dir;
		lifetime -= 1;
		return lifetime <= 0;
	}
};