#include "stdafx.h"
#include "SceneTitle.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"


SceneTitle::SceneTitle()
	:Scene(SceneIds::Title)
{
}

SceneTitle::~SceneTitle()
{
}


void SceneTitle::Init()
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
    texIds.push_back("graphics/axe1.png");
    texIds.push_back("graphics/axe2.png");

    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/Timber.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");


    AddGameObject(new SpriteGo("graphics/background.jpg"));

    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    element->SetMoveType(BackgroundElement::MoveType::Wave);

    tree1 = (Tree*)AddGameObject(new Tree());

    player1 = (Player*)AddGameObject(new Player());
    player1->SetPlayerType(PlayerType::Player1);


    go = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    go->SetString("Please press enter");
    go->SetCharacterSize(size);
    go->SetFillColor(sf::Color::White);
    go->SetPosition({ 525.f, 800.f });
    go->SetOrigin(Origins::MC);
    

    AddGameObject(new SpriteGo("graphics/Timber.png"));

	Scene::Init();
}
void SceneTitle::Enter()
{
    Scene::Enter();
    tree1->SetPosition({ 1536.f, 0.f });
    sf::Vector2f pos1 = tree1->GetPosition();
    pos1.y = 950.f;
    player1->SetPosition(pos1);

}
void SceneTitle::Exit()
{
	Scene::Exit();
}
void SceneTitle::Update(float dt)
{
    if (size > 100 || size < 70)
    {
        add *= -1.f;
    }
    size += add;
    go->SetCharacterSize(size);
    

    if (InputMgr::GetKeyDown(sf::Keyboard::Return))
    {
        SCENE_MGR.ChangeScene(SceneIds::mode);
    }

	Scene::Update(dt);
}