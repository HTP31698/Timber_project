#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:
	PlayerType playerType;
	PlayerType2 playerType2;


	sf::Sprite sprite;

	sf::Sprite axe;


	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> axePositions;
	std::vector<sf::Vector2f> scales;

	std::string texPlayerId;

	std::string axeTexId;
	std::string axe1TexId;
	std::string axe2TexId;

	std::string ripTexId;

	bool isAlive = true;
	bool drawAxe = false;
	

public:

	Player(const std::string& name = "");
	~Player() override = default;
	
	void SetPlayerType(PlayerType type);
	void SetPlayerType2(PlayerType2 type);

	void SetAlive(bool alive);
	void SetDrawAxe(bool draw) { drawAxe = draw; }

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetPosition(const sf::Vector2f& pos) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Reset(int playerNum = 1);
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

