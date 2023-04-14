#pragma once
#include "GameObject.h"

class Destroyer : public GameObject
{
public:
	void Update(float dt) override {};
	void AddToRenderList(RenderList& list) override;
	bool Collision(GameObject* other) override;
	inline const sf::FloatRect& GetGlobalBounds() override { return m_Area.getGlobalBounds(); }
private:
	sf::RectangleShape m_Area;
};