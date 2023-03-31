#pragma once
#include "GameObject.h"
#include "Bullet.h"
class Player : public GameObject
{
public:
	unsigned int m_Health;
private:
	sf::RectangleShape m_Body;
public:
	Player();
	bool Collision(GameObject* other) override;
	void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	Bullet* Shoot(Colors color);
	inline sf::FloatRect& GetGlobalBounds() const { return m_Body.getGlobalBounds(); }
	inline sf::Vector2f GetPosition() const { return m_Body.getPosition(); }
};