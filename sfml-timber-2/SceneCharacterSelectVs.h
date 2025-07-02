#pragma once
#include "Scene.h"
class SceneCharacterSelectVs : public Scene
{
protected:
	sf::Sprite player;
	sf::Sprite player1;
	sf::Sprite player2;

	sf::Sprite player3;
	sf::Sprite player4;
	sf::Sprite player5;

	std::string texPlayerId;
	std::string texPlayer1Id;
	std::string texPlayer2Id;

	int selectindex1 = 0;
	int selectindex2 = 0;

public:
	SceneCharacterSelectVs();
	~SceneCharacterSelectVs() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

