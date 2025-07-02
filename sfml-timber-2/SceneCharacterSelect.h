#pragma once
#include "Scene.h"

class Player;

class SceneCharacterSelect : public Scene
{
protected:
	sf::Sprite player1;
	sf::Sprite player2;

	std::string texPlayer1Id;
	std::string texPlayer2Id;

public:
	SceneCharacterSelect();
	~SceneCharacterSelect() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	
};

