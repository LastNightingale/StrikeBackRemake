#pragma once
#include "Physical.h"
#include "Bullet.h"
class Player : public Physical
{
public:	
	sf::Vector2f m_toTop;
	sf::Vector2f m_toBot;
public:
	Player();
	CollisionConsequence Collision(GameObject* other) override;
	void Update(float dt) override;
	Bullet* Shoot(Colors color);
	inline sf::Vector2f GetPosition() const { return m_Body.getPosition(); }
};