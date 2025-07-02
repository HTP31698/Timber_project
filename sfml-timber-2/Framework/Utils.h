#pragma once
#include <random>

class Utils
{
private:
	static std::random_device rd;
	static std::mt19937 gen;
	static PlayerType playerType;
	static PlayerType2 playerType2;

public:
	static void Init();
	//
	static void SetPlayerType(PlayerType player) { playerType = player; }
	static void SetPlayerType2(PlayerType2 player1) { playerType2 = player1; }

	static PlayerType GetPlayerType() { return playerType; }
	static PlayerType2 GetPlayerType2() { return playerType2; }

	// Random
	static float RandomValue(); // 0.0f ~ 1.0f
	static int RandomRange(int min, int maxExclude);
	static float RandomRange(float min, float max);

	// Origin
	static sf::Vector2f SetOrigin(sf::Transformable& obj, Origins preset, const sf::FloatRect bound);
	static sf::Vector2f SetOrigin(sf::Shape& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
};


