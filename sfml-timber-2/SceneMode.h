#pragma once
#include "Scene.h"
class UiHud;
class TextGo;
class SpriteGo;

class SceneMode : public Scene
{
protected:
	TextGo* textMessage1;
	TextGo* textMessage2;
	SpriteGo* solobg;
	SpriteGo* vsbg;


	int selectedIndex = 0;
public:
	SceneMode();
	~SceneMode() override;

	void Init() override;
	void Release() override;


	void Enter() override;
	void Exit() override;

	void Update(float dt) override;


};
