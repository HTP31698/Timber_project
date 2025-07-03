#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "SoundEffect.h"

SceneGame::SceneGame()
	: Scene(SceneIds::Game)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
	texIds.push_back("graphics/background.jpg");
	texIds.push_back("graphics/cloud.png");
	texIds.push_back("graphics/bee.png");
	texIds.push_back("graphics/tree.png");
	texIds.push_back("graphics/branch.png");
	texIds.push_back("graphics/player.png");
	texIds.push_back("graphics/player1.png");
	texIds.push_back("graphics/player2.png");
	texIds.push_back("graphics/axe.png");
	texIds.push_back("graphics/rip.png");
	texIds.push_back("graphics/log.png");
	texIds.push_back("graphics/gameover.png");

	fontIds.push_back("fonts/KOMIKAP_.ttf");

	soundIds.push_back("sound/chop.wav");
	soundIds.push_back("sound/death.wav");
	soundIds.push_back("sound/out_of_time.wav");

	//

	AddGameObject(new SpriteGo("graphics/background.jpg"));
	sf::FloatRect bounds = FRAMEWORK.GetWindowBounds();
	for (int i = 0; i < 3; ++i)
	{
		BackgroundElement* element = (BackgroundElement*)AddGameObject(
			new BackgroundElement("graphics/cloud.png"));
	}

	tree = (Tree*)AddGameObject(new Tree());

	BackgroundElement* element = (BackgroundElement*)AddGameObject(
		new BackgroundElement("graphics/bee.png"));
	element->minScale = 1.f;
	element->maxScale = 1.f;
	element->minY = 600;
	element->maxY = 800;
	element->minSpeed = 400;
	element->maxSpeed = 600;
	element->SetMoveType(BackgroundElement::MoveType::Wave);

	player = (Player*)AddGameObject(new Player());
	player->SetPlayerType(Utils::GetPlayerType());

	gameOverSprite = (SpriteGo*)AddGameObject(new SpriteGo("graphics/gameover.png"));
	gameOverSprite->SetOrigin(Origins::MC);
	gameOverSprite->SetPosition({ bounds.width * 0.5f, bounds.height * 0.5f });
	gameOverSprite->SetActive(false);

	textRetry = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	textRetry->SetString("Retry");
	textRetry->SetOrigin(Origins::MC);
	textRetry->SetPosition({ bounds.width * 0.5f - 200.f, bounds.height * 0.5f + 200.f });
	textRetry->SetCharacterSize(60);
	textRetry->SetFillColor(sf::Color::White);
	textRetry->SetActive(false);

	textQuit = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
	textQuit->SetString("Quit");
	textQuit->SetOrigin(Origins::MC);
	textQuit->SetPosition({ bounds.width * 0.5f + 200.f, bounds.height * 0.5f + 200.f });
	textQuit->SetCharacterSize(60);
	textQuit->SetFillColor(sf::Color::White);
	textQuit->SetActive(false);

	uiHud = (UiHud*)AddGameObject(new UiHud());
	soundEffect = (SoundEffect*)AddGameObject(new SoundEffect());

	Scene::Init();
}

void SceneGame::Enter()
{
	Scene::Enter();
	gameOverSprite->SetActive(false);
	textRetry->SetActive(false);
	textQuit->SetActive(false);
	tree->SetPosition({ 1980.f * 0.5f, 0.f });
	sf::Vector2f pos = tree->GetPosition();
	pos.y = 950.f;
	player->SetPosition(pos);

	score = 0;
	uiHud->SetScore(score);

	timer = timerMax;
	uiHud->SetTimeBar(timer / timerMax);

	uiHud->SetShowMassage(true);
	uiHud->SetMessage("Enter to Start!");
	gameover = false;
	selectedIndex = 0;

	player->Reset(1);
}

void SceneGame::Exit()
{
	Scene::Exit();
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	if (isPlaying)
	{
		selectedIndex = 0;
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			tree->UpdateBranches();
			player->SetSide(Sides::Left);
			if (tree->GetSide() == player->GetSide())
			{
				isPlaying = false;
				FRAMEWORK.SetTimeScale(0.f);
				player->SetAlive(false);
				soundEffect->PlaySoundDeath();
				gameOverSprite->SetActive(true);
				textRetry->SetActive(true);
				textQuit->SetActive(true);
				uiHud->SetShowMassage(false);
				uiHud->SetMessage("Enter to Restart!");
				gameover = true;

			}
			else
			{
				score += 10;
				soundEffect->PlaySoundChop();
				uiHud->SetScore(score);
				tree->AddLogs(Sides::Left);
				timer = timerMax;
			}
		}

		if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			tree->UpdateBranches();
			player->SetSide(Sides::Right);
			if (tree->GetSide() == player->GetSide())
			{
				isPlaying = false;
				FRAMEWORK.SetTimeScale(0.f);
				player->SetAlive(false);
				soundEffect->PlaySoundDeath();
				gameOverSprite->SetActive(true);
				textRetry->SetActive(true);
				textQuit->SetActive(true);
				uiHud->SetShowMassage(false);
				uiHud->SetMessage("Enter to Restart!");
				gameover = true;

			}
			else
			{
				score += 10;
				soundEffect->PlaySoundChop();
				uiHud->SetScore(score);
				tree->AddLogs(Sides::Right);
				timer = timerMax;
			}
		}


		player->SetDrawAxe(
			InputMgr::GetKey(sf::Keyboard::Left) ||
			InputMgr::GetKey(sf::Keyboard::Right));

		float speed = score / 100.f + 1;
		if (speed > 11)
		{
			speed = 11;
		}
		timer -= dt * speed;
		if (timer <= 0.f)
		{
			timer = 0.f;
			soundEffect->PlaySoundOutOfTime();

			isPlaying = false;
			FRAMEWORK.SetTimeScale(0.f);
			player->SetAlive(false);
			soundEffect->PlaySoundDeath();
			gameOverSprite->SetActive(true);
			textRetry->SetActive(true);
			textQuit->SetActive(true);
			uiHud->SetShowMassage(false);
			uiHud->SetMessage("Enter to Restart!");
			gameover = true;
		}
		uiHud->SetTimeBar(timer / timerMax);
	}

	else
	{
		if (gameover == true)
		{
			if (InputMgr::GetKeyDown(sf::Keyboard::Left))
			{
				textRetry->SetCharacterSize(100);
				textQuit->SetCharacterSize(60);
				selectedIndex = 0;
			}

			if (InputMgr::GetKeyDown(sf::Keyboard::Right))
			{
				textRetry->SetCharacterSize(60);
				textQuit->SetCharacterSize(100);
				selectedIndex = 1;
			}
		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
		{
			textRetry->SetCharacterSize(60);
			textQuit->SetCharacterSize(60);

			if (selectedIndex == 0)
			{
				FRAMEWORK.SetTimeScale(1.f);
				player->Reset(1);
				tree->Reset();
				isPlaying = true;

				score = 0;
				uiHud->SetScore(score);

				timer = timerMax;
				uiHud->SetTimeBar(timer / timerMax);
				gameOverSprite->SetActive(false);
				textRetry->SetActive(false);
				textQuit->SetActive(false);
				uiHud->SetShowMassage(false);
			}

			if (selectedIndex == 1)
			{
				SCENE_MGR.ChangeScene(SceneIds::Title);
			}
		}
	}
}
