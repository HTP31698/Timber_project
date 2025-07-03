#include "stdafx.h"
#include "SceneMode.h"
#include "SpriteGo.h"
#include "UiHud.h"
#include "TextGo.h"

SceneMode::SceneMode()
	: Scene(SceneIds::mode)
{
}
SceneMode::~SceneMode()
{
}
void SceneMode::Init()
{
	texIds.push_back("graphics/background.jpg");
	texIds.push_back("graphics/solobg.png");
	texIds.push_back("graphics/vsbg.png");
	fontIds.push_back("fonts/KOMIKAP_.ttf");


	AddGameObject(new SpriteGo("graphics/background.jpg"));

	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();



	solobg = (SpriteGo*)AddGameObject(new SpriteGo("graphics/solobg.png"));
	vsbg = (SpriteGo*)AddGameObject(new SpriteGo("graphics/vsbg.png"));

	solobg->SetPosition({ bounds.width * 0.25f, bounds.height * 0.4f });
	solobg->SetOrigin(Origins::MC);
	AddGameObject(solobg);
	vsbg->SetPosition({ bounds.width * 0.75f, bounds.height * 0.4f });
	vsbg->SetOrigin(Origins::MC);
	AddGameObject(vsbg);


	textMessage1 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	textMessage2 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));

	textMessage1->SetString("Solo Mode");
	textMessage1->SetOrigin(Origins::MC);
	textMessage1->SetPosition({ bounds.width * 0.25f, bounds.height * 0.8f });
	textMessage1->SetCharacterSize(100);
	textMessage1->SetFillColor(sf::Color::White);

	textMessage2->SetString("Vs Mode");
	textMessage2->SetOrigin(Origins::MC);
	textMessage2->SetPosition({ bounds.width * 0.75f, bounds.height * 0.8f });
	textMessage2->SetCharacterSize(100);
	textMessage2->SetFillColor(sf::Color::White);

	Scene::Init();

}

void SceneMode::Release()
{
}

void SceneMode::Enter()
{
	Scene::Enter();

}
void SceneMode::Exit()
{
	Scene::Exit();
}

void SceneMode::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		solobg->SetScale({ 1.2f,1.2f });
		vsbg->SetScale({ 1.0f,1.0f });
		textMessage1->SetCharacterSize(130);
		textMessage1->SetFillColor(sf::Color::Black);
		textMessage2->SetCharacterSize(100);
		textMessage2->SetFillColor(sf::Color::White);
		selectedIndex = 0;

	}
	else if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		solobg->SetScale({ 1.0f,1.0f });
		vsbg->SetScale({ 1.2f,1.2f });
		textMessage1->SetCharacterSize(100);
		textMessage1->SetFillColor(sf::Color::White);
		textMessage2->SetCharacterSize(170);
		textMessage2->SetFillColor(sf::Color::Black);
		selectedIndex = 1;

	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		if (selectedIndex == 0)
		{
			SCENE_MGR.ChangeScene(SceneIds::CharacterSelect);
		}
		else if (selectedIndex == 1)
		{
			SCENE_MGR.ChangeScene(SceneIds::CharacterSelectVs);
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{

		SCENE_MGR.ChangeScene(SceneIds::Title);

	}
}