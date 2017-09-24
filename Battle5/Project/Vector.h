#pragma once

/*
 * A simple vector class with two elements
 * for position and direction calculations.
 */
struct Vector
{
	float x;
	float y;

	Vector() : x(0),
		y(0)
	{
	}
	Vector(float x, float y) : x(x),
		y(y)
	{
	}

	Vector& operator+=(const Vector& vIn)
	{
		x += vIn.x;
		y += vIn.y;
		return *this;
	}
};