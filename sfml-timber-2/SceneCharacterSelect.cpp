#include "stdafx.h"
#include "SceneCharacterSelect.h"
#include "Player.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneCharacterSelect::SceneCharacterSelect()
	:Scene(SceneIds::CharacterSelect)
{

}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player1.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/background.jpg");

	AddGameObject(new SpriteGo("graphics/background.jpg"));

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Select Character!");
	go->SetCharacterSize(50);
	go->SetFillColor(sf::Color::White);
	go->SetOrigin(Origins::MC);
	go->SetPosition({1920 *0.5f , 100});
	AddGameObject(go);
}

void SceneCharacterSelect::Enter()
{
	Scene::Enter();
	
	player.setTexture(TEXTURE_MGR.Get("graphics/player.png"));
	player1.setTexture(TEXTURE_MGR.Get("graphics/player1.png"));
	player2.setTexture(TEXTURE_MGR.Get("graphics/player2.png"));
	Utils::SetOrigin(player, Origins::BC);
	Utils::SetOrigin(player1, Origins::BC);
	Utils::SetOrigin(player2, Origins::BC);
	sf::Vector2f bounds = FRAMEWORK.GetWindowSizeF();
	player.setPosition({ bounds.x * 0.2f , bounds.y * 0.7f });
	player1.setPosition({ bounds.x * 0.5f , bounds.y * 0.7f });
	player2.setPosition({ bounds.x * 0.8f,  bounds.y * 0.7f });
	player.setScale({ 1.5f, 1.5f });
	player1.setScale({ 1.f, 1.f });
	player2.setScale({ 1.f, 1.f });
	

}

void SceneCharacterSelect::Exit()
{
	Scene::Exit();
}

void SceneCharacterSelect::Update(float dt)
{
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		selectindex--;
		if (selectindex < 0)
		{
			selectindex = 0;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		selectindex++;
		if (selectindex > 2)
		{
			selectindex = 2;
		}
	}

	if (selectindex == 0)
	{
		player.setScale({ 1.5f, 1.5f });
		player1.setScale({ 1.f, 1.f });
		player2.setScale({ 1.f, 1.f });
		Utils::SetPlayerType(PlayerType::Player);
	}
	if (selectindex == 1)
	{
		player.setScale({ 1.f, 1.f });
		player1.setScale({ 1.5f, 1.5f });
		player2.setScale({ 1.f, 1.f });
		Utils::SetPlayerType(PlayerType::Player1);
	}
	if (selectindex == 2)
	{
		player.setScale({ 1.f, 1.f });
		player1.setScale({ 1.f, 1.f });
		player2.setScale({ 1.5f, 1.5f });
		Utils::SetPlayerType(PlayerType::Player2);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Return))
	{
		SCENE_MGR.ChangeScene(SceneIds::Game);
	}
}


void SceneCharacterSelect::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(player);
	window.draw(player1);
	window.draw(player2);
}
