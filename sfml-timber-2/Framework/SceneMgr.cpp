#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneGameVs.h"
#include "SceneDev1.h"
#include "SceneDev2.h"
#include "SceneTitle.h"
#include "SceneCharacterSelect.h"
#include "SceneCharacterSelectVs.h"
#include "SceneMode.h"

void SceneMgr::Init()
{
	scenes.push_back(new SceneTitle());
	scenes.push_back(new SceneMode());
	scenes.push_back(new SceneCharacterSelect());
	scenes.push_back(new SceneCharacterSelectVs());
	scenes.push_back(new SceneGame());
	scenes.push_back(new SceneGameVs());
	scenes.push_back(new SceneDev2());

	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}

	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
