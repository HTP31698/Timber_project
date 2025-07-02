#pragma once
#include "Scene.h"

class Player;

class SceneCharacterSelect : public Scene
{
protected:
	sf::Sprite player;
	sf::Sprite player1;
	sf::Sprite player2;

	std::string texPlayerId;
	std::string texPlayer1Id;
	std::string texPlayer2Id;

	int selectindex = 0;

public:
	SceneCharacterSelect();
	~SceneCharacterSelect() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	
};

