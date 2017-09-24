#include <iostream>
#include <chrono>
#include <thread>

#include "../Project/ParticleSource.h"

void PrintParticle(Particle* p);

int main()
{
	std::cout << "Constructing a ParticleSource which uses an ObjectPool<Particle>" << std::endl;
	ParticleSource pSource(10, 10);
	unsigned int timer = 10;

	std::cout << std::endl << "Iterating and printing particle data for " << timer << " iterations." << std::endl;
	while (timer--)
	{
		pSource.Update();
		pSource.FunctionOverAll(PrintParticle);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << "Done!" << std::endl;

	system("pause");
	return 0;
}

void PrintParticle(Particle* p)
{
	std::cout << "x: " << p->pos.x << ", y: " << p->pos.y << std::endl;
}