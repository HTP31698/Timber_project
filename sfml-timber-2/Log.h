#pragma once
#include "GameObject.h"
class Log : public GameObject
{
protected:
	sf::Sprite log;
	sf::Vector2f direction;
	sf::Vector2f velocity;
	
	std::string texIdLog;
	
	float logSpeed = 2000.f;
	sf::Vector2f gravity;
	sf::Vector2f logInitPosition;
public:

	Log(const std::string& name = "");
	~Log() override = default;

	void setDirection(Sides side);
	// GameObject을(를) 통해 상속됨
	void Init() override;

	void Release() override;

	void Reset() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;

};

