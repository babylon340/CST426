#include <iostream>

#include "../Project/Audio.h"
#include "../Project/NullAudio.h"
#include "../Project/LoggingAudioService.h"
#include "../Project/ServiceLocator.h"

int main()
{
	std::cout << "Attaching logging interface to audio service locator" << std::endl;
	ServiceLocator::Service()->SetAudioService(new LoggingAudioService(std::cout, ServiceLocator::Service()->GetAudioService()));

	std::cout << "Registerring songs" << std::endl;
	unsigned int laserBlast = ServiceLocator::Service()->GetAudioService()->RegisterAudio("laser.mp3");
	unsigned int engineHum = ServiceLocator::Service()->GetAudioService()->RegisterAudio("engine.mp3");
	unsigned int deathSound = ServiceLocator::Service()->GetAudioService()->RegisterAudio("wilhelm.mp3");

	std::cout << "Playing engine hum" << std::endl;
	ServiceLocator::Service()->GetAudioService()->PlayAudio(engineHum);

	std::cout << "Playing scream" << std::endl;
	ServiceLocator::Service()->GetAudioService()->PlayAudio(deathSound);

	std::cout << "Calling StopAllAudio()" << std::endl;
	ServiceLocator::Service()->GetAudioService()->StopAllAudio();

	std::cout << "Playing unregistered sound" << std::endl;
	ServiceLocator::Service()->GetAudioService()->PlayAudio(10);

	system("pause");
	return 0;
}