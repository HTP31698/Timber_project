#include "stdafx.h"
#include "SceneCharacterSelect.h"
#include "Player.h"
#include "SpriteGo.h"
SceneCharacterSelect::SceneCharacterSelect()
	:Scene(SceneIds::CharacterSelect)
{

}

SceneCharacterSelect::~SceneCharacterSelect()
{
}

void SceneCharacterSelect::Init()
{

	texIds.push_back("graphics/player1.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/background.png");
	AddGameObject(new SpriteGo("graphics/background.png"));

}

void SceneCharacterSelect::Enter()
{
	Scene::Enter();
	
	
	player1.setTexture(TEXTURE_MGR.Get("graphics/player1.png"));
	player2.setTexture(TEXTURE_MGR.Get("graphics/player2.png"));
	Utils::SetOrigin(player1, Origins::BC);
	Utils::SetOrigin(player2, Origins::BC);
	sf::Vector2f bounds = FRAMEWORK.GetWindowSizeF();
	player1.setPosition({ bounds.x * 0.3f , bounds.y * 0.7f });
	player2.setPosition({ bounds.x * 0.6f,  bounds.y * 0.7f });
	player1.setScale({ 2.f, 2.f });
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
		player1.setScale({ 2.f, 2.f });
		player2.setScale({ 1.f, 1.f });
		Utils::SetPlayerType(PlayerType::Player1);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		player1.setScale({ 1.f, 1.f });
		player2.setScale({ 2.f, 2.f });
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
	window.draw(player1);
	window.draw(player2);
}
