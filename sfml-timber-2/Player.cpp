#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::SetPlayerType(PlayerType type)
{
	playerType = type;
}

void Player::SetAlive(bool alive)
{
	isAlive = alive;
	if (isAlive)
	{
		if (playerType == PlayerType::player)
		{
			sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
		}
		if (playerType == PlayerType::player1)
		{
			sprite.setTexture(TEXTURE_MGR.Get(texPlayer1Id));
		}
		if (playerType == PlayerType::player2)
		{
			sprite.setTexture(TEXTURE_MGR.Get(texPlayer2Id));
		}
	}
	else
	{
		sprite.setTexture(TEXTURE_MGR.Get(ripTexId));
		sprite.setScale({ 1.f, 1.f });
		drawAxe = false;
	}
	Utils::SetOrigin(sprite, Origins::BC);
}

void Player::SetSide(Sides s)
{
	side = s;

	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);

	axe.setPosition(position + axePositions[(int)side]);
	axe.setScale(scales[(int)side]);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
	axe.setPosition(position + axePositions[(int)side]);
}

void Player::Init()
{
	texPlayerId = "graphics/player.png";
	texPlayer1Id = "graphics/player1.png";
	texPlayer2Id = "graphics/player2.png";
	axeTexId = "graphics/axe.png";
	axe1TexId = "graphics/axe1.png";
	axe2TexId = "graphics/axe2.png";
	ripTexId = "graphics/rip.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f, 0.f };
	positions[(int)Sides::Right] = { 300.f, 0.f };

	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f, 1.f };
	scales[(int)Sides::Right] = { 1.f, 1.f };

	axePositions.resize(2);
	axePositions[(int)Sides::Left] = { -165.f, -55.f };
	axePositions[(int)Sides::Right] = { 165.f, -55.f };
}

void Player::Release()
{
}

void Player::Reset()
{
	if (playerType == PlayerType::player)
	{
		sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
		Utils::SetOrigin(sprite, Origins::BC);
	}
	if (playerType == PlayerType::player1)
	{
		sprite.setTexture(TEXTURE_MGR.Get(texPlayer1Id));
		Utils::SetOrigin(sprite, Origins::BC);
	}
	if (playerType == PlayerType::player2)
	{
		sprite.setTexture(TEXTURE_MGR.Get(texPlayer2Id));
		Utils::SetOrigin(sprite, Origins::BC);
	}

	axe.setTexture(TEXTURE_MGR.Get(axeTexId));
	Utils::SetOrigin(axe, Origins::BC);

	SetSide(Sides::Right);
}

void Player::Update(float dt)
{

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (drawAxe)
	{
		window.draw(axe);
	}
}
