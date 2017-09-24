#pragma once
#include <vector>
#include <functional>

#include "ObjectPool.h"
#include "Particle.h"
#include "CirclePointPicker.h"

/*
 * ParticleSource will, once per frame, create a new particle
 * from an ObjectPool<Particle>, update all particles, and
 * remove dead particles from circulation.
 *
 * It also provides a basic method for running all existing
 * particles through a user-provided function.
 */
class ParticleSource
{
private:
	ObjectPool<Particle> source;
	std::vector<Particle*> particles;
	float lifetime;
public:
	ParticleSource(unsigned int size, float lifetime) : source(size),
		lifetime(lifetime)
	{
	}
	~ParticleSource()
	{
		for (std::vector<Particle*>::iterator itr = particles.begin();
			itr != particles.end(); ++itr)
		{
			source.Destroy(*itr);
		}
	}

	void Update()
	{
		if (source.AvailableSpace())
		{
			particles.push_back(source.Create(PointOnACircle(), PointOnACircle(), lifetime));
		}

		for (std::vector<Particle*>::iterator itr = particles.begin();
			itr != particles.end();)
		{
			if ((*itr)->Update())
			{
				Particle* temp = *itr;
				itr = particles.erase(itr);
				source.Destroy(temp);
			}
			else
			{
				++itr;
			}
		}
	}

	void FunctionOverAll(std::function<void(Particle*)> callback)
	{
		for (std::vector<Particle*>::iterator itr = particles.begin();
			itr != particles.end(); ++itr)
		{
			callback(*itr);
		}
	}
};