#pragma once
#include "GameObject.h"
class SoundEffect : public GameObject
{
protected:
	sf::Sound soundChop;
	sf::Sound soundDeath;
	sf::Sound soundOutOfTime;

	std::string bufferChopId;
	std::string bufferDeathId;
	std::string bufferOutOfTimeId;
public:
	SoundEffect(const std::string& name = "");
	~SoundEffect() override = default;

	void PlaySoundChop();
	void PlaySoundOutOfTime();
	void PlaySoundDeath();
	// GameObject을(를) 통해 상속됨
	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

};

