#pragma once
#define _USE_MATH_DEFINES
#include <cstdlib>
#include "Vector.h"

/*
 * Generates random points on a circle for both
 * initial particle position and particle direction.
 */
Vector PointOnACircle(float radius = 1)
{
	float angle = rand() / static_cast<float>(RAND_MAX) * 2 * 3.1415927;
	
	Vector v(radius * cos(angle), radius * sin(angle));

	return v;
}