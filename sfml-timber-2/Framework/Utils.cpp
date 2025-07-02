#include "stdafx.h"
#include "Utils.h"

std::random_device Utils::rd;
std::mt19937 Utils::gen;
PlayerType Utils::playerType = PlayerType::Player1;
PlayerType2 Utils::playerType2 = PlayerType2::Player3;


void Utils::Init()
{
    gen.seed(rd());
}

float Utils::RandomValue()
{
    std::uniform_real_distribution<float> dist(0.f, 1.f);
    return dist(gen);
}

int Utils::RandomRange(int min, int maxExclude)
{
    std::uniform_int_distribution<int> dist(min, maxExclude - 1);
	return dist(gen);
}

float Utils::RandomRange(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

sf::Vector2f Utils::SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect rect)
{
    sf::Vector2f newOrigin(rect.width, rect.height);
    newOrigin.x *= ((int)preset % 3) * 0.5f;
    newOrigin.y *= ((int)preset / 3) * 0.5f;
    obj.setOrigin(newOrigin);
    return newOrigin;
}

sf::Vector2f Utils::SetOrigin(sf::Shape& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Text& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}

sf::Vector2f Utils::SetOrigin(sf::Sprite& obj, Origins preset)
{
    return SetOrigin(obj, preset, obj.getLocalBounds());
}


std::string Utils::GetPlayerTexture(int playerNum)
{
    if (playerNum == 1) {
        // Player1¿ë
        switch (playerType) {
        case PlayerType::Player: return "graphics/player.png";
        case PlayerType::Player1: return "graphics/player1.png";
        case PlayerType::Player2: return "graphics/player2.png";
        default: return "graphics/player.png";
        }
    }
    else if (playerNum == 2) {
        // Player2¿ë
        switch (playerType2) {
        case PlayerType2::Player3: return "graphics/player.png";
        case PlayerType2::Player4: return "graphics/player1.png";
        case PlayerType2::Player5: return "graphics/player2.png";
        default: return "graphics/player.png";
        }
    }
    return "graphics/player.png";
}