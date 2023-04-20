#pragma once
#include "Physical.h"
#include "Enemy.h"

class Spawner : public Physical
{
private:
	//sf::RectangleShape m_Area;
public:
	Spawner();
	void AddToRenderList(RenderList& list) override {};
	CollisionConsequence Collision(GameObject* other) override;
	//sf::FloatRect GetGlobalBounds() override { return sf::FloatRect(); }
	Enemy* SpawnEnemy();
};