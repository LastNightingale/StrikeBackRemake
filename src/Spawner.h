#pragma once
#include "GameObject.h"
#include "Enemy.h"

class Spawner : public GameObject
{
private:
	sf::RectangleShape m_Area;
public:
	Spawner();
	void AddToRenderList(RenderList& list) override {};
	CollisionConsequence Collision(GameObject* other) override;
	sf::FloatRect GetGlobalBounds() { return sf::FloatRect(); }
	Enemy* SpawnEnemy();
};