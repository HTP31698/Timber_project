#pragma once
#include "Scene.h"
class Player;
class Tree;
class UiHud;

class GameSceneVs2 : public Scene
{
protected:
	Player* player;
	Tree* tree;
	UiHud* uiHud;

	bool isPlaying = false;
	int score = 0;
	float timer = 0.f;
	float timerMax = 5.f;

public:
	GameSceneVs2();
	~GameSceneVs2() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

