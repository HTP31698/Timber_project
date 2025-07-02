#include "stdafx.h"
#include "Log.h"

Log::Log(const std::string& name)
	:GameObject(name)
{
}

void Log::setDirection(Sides side)
{
	switch (side)
	{
	case Sides::Left:
		direction = { 1.f, -1.f };
		break;
	case Sides::Right:
		direction = { -1.f, -1.f };
		break;
	}
	velocity = direction * logSpeed;
}

void Log::Init()
{
	texIdLog = "graphics/log.png";
	gravity = { 0.f, 6000.f };
	logInitPosition = { 1920 * .5f, 900 };
	
}

void Log::Release()
{
}

void Log::Reset()
{
	log.setTexture(TEXTURE_MGR.Get(texIdLog), true);
	Utils::SetOrigin(log, Origins::BC);
	log.setPosition(logInitPosition);
	SetPosition(logInitPosition);
	
}

void Log::Update(float dt)
{
	if (GetActive())
	{
		
		velocity += gravity * dt;
		sf::Vector2f position = GetPosition();
		position += velocity * dt;
		log.setPosition(position);
		SetPosition(position);

		if (position.y >1080)
		{
			SetActive(false);
			position = logInitPosition;
			log.setPosition(logInitPosition);
			SetPosition(logInitPosition);
		}
	}
	
}

void Log::Draw(sf::RenderWindow& window)
{
	window.draw(log);
}
