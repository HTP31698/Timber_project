#include "stdafx.h"
#include "SoundEffect.h"

SoundEffect::SoundEffect(const std::string& name)
	:GameObject(name)
{
}

void SoundEffect::PlaySoundChop()
{
	soundChop.play();
}

void SoundEffect::PlaySoundOutOfTime()
{
	soundOutOfTime.play();
}

void SoundEffect::PlaySoundDeath()
{
	soundDeath.play();
}

void SoundEffect::Init()
{
	bufferChopId = "sound/chop.wav";
	bufferDeathId = "sound/death.wav";
	bufferOutOfTimeId = "sound/out_of_time.wav";

}

void SoundEffect::Release()
{
}

void SoundEffect::Reset()
{
	soundChop.setBuffer(SOUNDBUFFER_MGR.Get(bufferChopId));
	soundDeath.setBuffer(SOUNDBUFFER_MGR.Get(bufferDeathId));
	soundOutOfTime.setBuffer(SOUNDBUFFER_MGR.Get(bufferOutOfTimeId));

}

void SoundEffect::Update(float dt)
{
}

void SoundEffect::Draw(sf::RenderWindow& window)
{
}
