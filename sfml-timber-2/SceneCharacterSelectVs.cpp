#include "stdafx.h"
#include "SceneCharacterSelectVs.h"
#include "Player.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneCharacterSelectVs::SceneCharacterSelectVs()
	:Scene(SceneIds::CharacterSelectVs)
{
}

SceneCharacterSelectVs::~SceneCharacterSelectVs()
{
}


void SceneCharacterSelectVs::Init()
{
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player1.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/background.jpg");

	AddGameObject(new SpriteGo("graphics/background.jpg"));

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("Select Character Vs!");
	go->SetCharacterSize(50);
	go->SetFillColor(sf::Color::Black);
	go->SetOrigin(Origins::MC);
	go->SetPosition({ 1920 * 0.5f , 100 });
	AddGameObject(go);

	TextGo* go1 = new TextGo("fonts/KOMIKAP_.ttf");
	go1->SetString("Player 1 Select!");
	go1->SetCharacterSize(40);
	go1->SetFillColor(sf::Color::Red);
	go1->SetOrigin(Origins::MC);
	go1->SetPosition({ 1920 * 0.5f , 200 });
	AddGameObject(go1);

	TextGo* go2 = new TextGo("fonts/KOMIKAP_.ttf");
	go2->SetString("Player 2 Select!");
	go2->SetCharacterSize(40);
	go2->SetFillColor(sf::Color::Blue);
	go2->SetOrigin(Origins::MC);
	go2->SetPosition({ 1920 * 0.5f , 600.f });
	AddGameObject(go2);

}

void SceneCharacterSelectVs::Enter()
{
	Scene::Enter();
	sf::Vector2f bounds = FRAMEWORK.GetWindowSizeF();

	player.setTexture(TEXTURE_MGR.Get("graphics/player.png"));
	player1.setTexture(TEXTURE_MGR.Get("graphics/player1.png"));
	player2.setTexture(TEXTURE_MGR.Get("graphics/player2.png"));
	Utils::SetOrigin(player, Origins::BC);
	Utils::SetOrigin(player1, Origins::BC);
	Utils::SetOrigin(player2, Origins::BC);
	player.setPosition({ bounds.x * 0.2f , bounds.y * 0.5f });
	player1.setPosition({ bounds.x * 0.5f , bounds.y * 0.5f });
	player2.setPosition({ bounds.x * 0.8f,  bounds.y * 0.5f });
	player.setScale({ 1.5f, 1.5f });
	player1.setScale({ 1.f, 1.f });
	player2.setScale({ 1.f, 1.f });

	player3.setTexture(TEXTURE_MGR.Get("graphics/player.png"));
	player4.setTexture(TEXTURE_MGR.Get("graphics/player1.png"));
	player5.setTexture(TEXTURE_MGR.Get("graphics/player2.png"));
	Utils::SetOrigin(player3, Origins::BC);
	Utils::SetOrigin(player4, Origins::BC);
	Utils::SetOrigin(player5, Origins::BC);
	player3.setPosition({ bounds.x * 0.2f , bounds.y * 0.9f });
	player4.setPosition({ bounds.x * 0.5f , bounds.y * 0.9f });
	player5.setPosition({ bounds.x * 0.8f,  bounds.y * 0.9f });
	player3.setScale({ 1.5f, 1.5f });
	player4.setScale({ 1.f, 1.f });
	player5.setScale({ 1.f, 1.f });
}

void SceneCharacterSelectVs::Exit()
{
	Scene::Exit();
}

void SceneCharacterSelectVs::Update(float dt)
{
	Scene::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::A))
	{
		selectindex1--;
		if (selectindex1 < 0)
		{
			selectindex1 = 0;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::D))
	{
		selectindex1++;
		if (selectindex1 > 2)
		{
			selectindex1 = 2;
		}
	}

	if (selectindex1 == 0)
	{
		player.setScale({ 1.5f, 1.5f });
		player1.setScale({ 1.f, 1.f });
		player2.setScale({ 1.f, 1.f });
		Utils::SetPlayerType(PlayerType::Player);
	}
	if (selectindex1 == 1)
	{
		player.setScale({ 1.f, 1.f });
		player1.setScale({ 1.5f, 1.5f });
		player2.setScale({ 1.f, 1.f });
		Utils::SetPlayerType(PlayerType::Player1);
	}
	if (selectindex1 == 2)
	{
		player.setScale({ 1.f, 1.f });
		player1.setScale({ 1.f, 1.f });
		player2.setScale({ 1.5f, 1.5f });
		Utils::SetPlayerType(PlayerType::Player2);
	}

	// 여기부턴 2p가 고른다
	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		selectindex2--;
		if (selectindex2 < 0)
		{
			selectindex2 = 0;
		}
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		selectindex2++;
		if (selectindex2 > 2)
		{
			selectindex2 = 2;
		}
	}

	if (selectindex2 == 0)
	{
		player3.setScale({ 1.5f, 1.5f });
		player4.setScale({ 1.f, 1.f });
		player5.setScale({ 1.f, 1.f });
		Utils::SetPlayerType2(PlayerType2::Player3);
	}
	if (selectindex2 == 1)
	{
		player3.setScale({ 1.f, 1.f });
		player4.setScale({ 1.5f, 1.5f });
		player5.setScale({ 1.f, 1.f });
		Utils::SetPlayerType2(PlayerType2::Player4);
	}
	if (selectindex2 == 2)
	{
		player3.setScale({ 1.f, 1.f });
		player4.setScale({ 1.f, 1.f });
		player5.setScale({ 1.5f, 1.5f });
		Utils::SetPlayerType2(PlayerType2::Player5);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Return))
	{
		SCENE_MGR.ChangeScene(SceneIds::GameVs);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{

		SCENE_MGR.ChangeScene(SceneIds::mode);

	}
}

void SceneCharacterSelectVs::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	window.draw(player);
	window.draw(player1);
	window.draw(player2);
	window.draw(player3);
	window.draw(player4);
	window.draw(player5);

}