#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;

class SceneGameVs : public Scene
{
protected:
	Player* player1;
	Player* player2;
	Tree* tree1;
	Tree* tree2;

	UiHud* uiHud1;
	UiHud* uiHud2;


	bool isPlaying1 = false;
	bool isPlaying2 = false;
	int score1 = 0;
	int score2 = 0;
	float timer = 0.f;
	float timerMax = 30.f;

public:
	SceneGameVs();
	~SceneGameVs() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

};

