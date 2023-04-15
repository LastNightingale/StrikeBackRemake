#pragma once
#include "GameObject.h"

class Destroyer : public GameObject
{
public:
	Destroyer();
	void Update(float dt) override {};
	void AddToRenderList(RenderList& list) override {};
	CollisionConsequence Collision(GameObject* other) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Area.getGlobalBounds(); }
private:
	sf::RectangleShape m_Area;
};


