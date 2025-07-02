#pragma once
#include "GameObject.h"
class UiHud : public GameObject
{
protected:
	sf::Text textScore;
	sf::Text textMessage;
	sf::RectangleShape timeBar;

	std::string fontId;
	bool isShowMessage;

	sf::Vector2f timeBarSize;

public:
	UiHud(const std::string& name = "");
	~UiHud() override = default;

	void SetScore(int score);
	void SetScorePosition(const sf::Vector2f& pos);
	void setScoreSize(int size);
	void SetMessage(const std::string& msg);
	void SetMessageSize(int size);
	void SetMessagePosition(const sf::Vector2f& pos);
	void SetShowMassage(bool show) { isShowMessage = show; }
	void SetTimeBar(float value); // 0.f ~ 1.f

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};

