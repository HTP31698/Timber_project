#include "stdafx.h"
#include "SceneGameVs.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"

SceneGameVs::SceneGameVs()
	:Scene(SceneIds::GameVs)
{
}

SceneGameVs::~SceneGameVs()
{
}


void SceneGameVs::Init()
{
    texIds.push_back("graphics/background.png");
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
    texIds.push_back("graphics/log.png");
    fontIds.push_back("fonts/KOMIKAP_.ttf");


    AddGameObject(new SpriteGo("graphics/background.png"));

    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    tree1 = (Tree*)AddGameObject(new Tree());

    tree2 = (Tree*)AddGameObject(new Tree());

    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));

    player1 = (Player*)AddGameObject(new Player()); 
    player2 = (Player*)AddGameObject(new Player());


    uiHud1 = (UiHud*)AddGameObject(new UiHud());
    uiHud2 = (UiHud*)AddGameObject(new UiHud());

    Scene::Init();
}


void SceneGameVs::Enter()
{
    Scene::Enter();
    tree1->SetPosition({ 384.f, 0.f });
    sf::Vector2f pos1 = tree1->GetPosition();
    pos1.y = 950.f;
    player1->SetPosition(pos1);

    tree2->SetPosition({ 1536.f, 0.f });
    sf::Vector2f pos2 = tree2->GetPosition();
    pos2.y = 950.f;
    player2->SetPosition(pos2);

    score1 = 0;
    uiHud1->SetScore(score1);

    score2 = 0;
    uiHud2->SetScore(score2);
    uiHud2->SetScorePosition({ 1300.f, 0.f });

    timer = timerMax;
    uiHud1->SetTimeBar(timer / timerMax);

    uiHud1->SetShowMassage(true);
    uiHud1->SetMessage("Enter to Start!");
    uiHud2->SetShowMassage(false);
    uiHud2->SetTimeBar(0.f);
}

void SceneGameVs::Exit()
{
    Scene::Exit();
}

void SceneGameVs::Update(float dt)
{
    Scene::Update(dt);

    // player 1 이 동작
    if (isPlaying1)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::A))
        {
            tree1->UpdateBranches();
            tree1->AddLogs(Sides::Left);
            player1->SetSide(Sides::Left);
            if (tree1->GetSide() == player1->GetSide())
            {
                isPlaying1 = false;
                player1->SetAlive(false);
            }
            else
            {
                score1 += 10;
                uiHud1->SetScore(score1);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::D))
        {
            tree1->UpdateBranches();
            player1->SetSide(Sides::Right);
            tree1->AddLogs(Sides::Right);
            if (tree1->GetSide() == player1->GetSide())
            {
                isPlaying1 = false;
                player1->SetAlive(false);
            }
            else
            {
                score1 += 10;
                uiHud1->SetScore(score1);
            }
        }

        player1->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::A) || 
            InputMgr::GetKey(sf::Keyboard::D));
    }

    //player 2가 동작
    if (isPlaying2)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree2->UpdateBranches();
            player2->SetSide(Sides::Left);
            tree2->AddLogs(Sides::Left);
            if (tree2->GetSide() == player2->GetSide())
            {
                isPlaying2 = false;
                player2->SetAlive(false);
            }
            else
            {
                score2 += 10;
                uiHud2->SetScore(score2);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree2->UpdateBranches();
            player2->SetSide(Sides::Right);
            tree2->AddLogs(Sides::Right);
            if (tree2->GetSide() == player2->GetSide())
            {
                isPlaying2 = false;
                player2->SetAlive(false);
            }
            else
            {
                score2 += 10;
                uiHud2->SetScore(score2);
            }
        }

        player2->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) ||
            InputMgr::GetKey(sf::Keyboard::Right));
    }

    // Enter를 눌러 초기화
    else if(!isPlaying1 && !isPlaying2)
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player1->Reset();
            player2->Reset();
            tree1->Reset();
            tree2->Reset();
            isPlaying1 = true;
            isPlaying2 = true;

            score1 = 0;
            uiHud1->SetScore(score1);
            score2 = 0;
            uiHud2->SetScore(score2);

            timer = timerMax;
            uiHud1->SetTimeBar(timer / timerMax);

            uiHud1->SetShowMassage(false);
        }
    }

    // 승리 조건들
    if (isPlaying1 == true && isPlaying2 == false)
    {
        if (score1 > score2)
        {
            FRAMEWORK.SetTimeScale(0.f);
            isPlaying1 = false;

            uiHud1->SetShowMassage(true);
            uiHud1->SetMessage("Player 1 Win!! Enter to Restart!");
        }
        uiHud1->SetTimeBar(timer / timerMax);
    }

    else if (isPlaying1 == false && isPlaying2 == true)
    {
        if (score1 < score2)
        {
            FRAMEWORK.SetTimeScale(0.f);
            isPlaying2 = false;

            uiHud1->SetShowMassage(true);
            uiHud1->SetMessage("Player 2 Win!! Enter to Restart!");
        }
        uiHud1->SetTimeBar(timer / timerMax);
    }

    else if (isPlaying1 == false && isPlaying2 == false )
    {
        FRAMEWORK.SetTimeScale(0.f);

        uiHud1->SetShowMassage(true);
        if (score1 > score2)
        {
            uiHud1->SetMessage("Player 1 Win!! Enter to Restart!");
        }
        else if (score1 < score2)
        {
            uiHud1->SetMessage("Player 2 Win!! Enter to Restart!");
        }
        uiHud1->SetTimeBar(timer / timerMax);
    }
    

    timer -= dt;
    if (timer <= 0.f)
    {
        timer = 0.f;

        isPlaying1 = false;
        isPlaying2 = false;
        FRAMEWORK.SetTimeScale(0.f);

        uiHud1->SetShowMassage(true);
        if(score1 > score2)
        { 
          uiHud1->SetMessage("Player 1 Win!! Enter to Restart!");
        }
        else if (score1 < score2)
        {
          uiHud1->SetMessage("Player 2 Win!! Enter to Restart!");
        }
        else if (score1 == score2)
        {
          uiHud1->SetMessage("Draw!! Enter to Restart!");
        }
    }
    uiHud1->SetTimeBar(timer / timerMax);
 



}