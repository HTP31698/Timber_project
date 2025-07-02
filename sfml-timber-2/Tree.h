#pragma once
#include "GameObject.h"
#include "Log.h"
class Tree : public GameObject
{
protected:
	sf::Sprite tree;
	
	std::vector<Log*> logs;
	std::vector<sf::Sprite> branches;
	std::vector<Sides> branchesSide;

	std::string texIdTree;
	std::string texIdBranch;
	std::string texIdLog;

	

public:
	Tree() = default;
	~Tree() override = default;

	void SetPosition(const sf::Vector2f& pos) override;
	Sides UpdateBranches();

	Sides GetSide() const { return branchesSide[branchesSide.size() - 1]; }
	void AddLogs(Sides side);
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;


};

