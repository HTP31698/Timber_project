#pragma once
#include "Scene.h"
class Player;
class Tree;
class TextGo;

class SceneTitle : public Scene
{
protected:

	TextGo* go;
	Player* player1;
	Tree* tree1;

	sf::Text text;
	std::string fontId;

	float size = 70.f;
	float add = 0.1f;

public:
	SceneTitle();
	~SceneTitle();



	void Init() override;
	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

