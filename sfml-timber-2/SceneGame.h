#pragma once
#include "Scene.h"

class Player;
class Tree;
class UiHud;
class SoundEffect;
class SpriteGo;
class TextGo;

class SceneGame : public Scene
{
protected:
	Player* player;
	Tree* tree;
	UiHud* uiHud;
	SoundEffect* soundEffect;
	SpriteGo* gameOverSprite = nullptr;
	TextGo* textRetry = nullptr;
	TextGo* textQuit = nullptr;
	int selectedIndex = 0;
	bool isPlaying = false;
	int score = 0;
	float timer = 0.f;
	float timerMax = 5.f;

	bool gameover = false;

public:
	SceneGame();
	~SceneGame() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;
};

