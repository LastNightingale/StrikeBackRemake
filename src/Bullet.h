#pragma once
#include <sfml/Graphics.hpp>
#include "GameObject.h"

class Bullet : public GameObject
{
public:
private:
	sf::RectangleShape m_Body;
public:
	Bullet(float y, Colors color);
	CollisionConsequence Collision(GameObject* other) override;
	void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	inline const sf::Color& GetColor() { return m_Body.getFillColor(); }
};