#pragma once
#include "Physical.h"
#include "Player.h"

class BackStrike : public Physical
{
private:
	Player* m_Aim;
public:
	BackStrike(sf::Vector2f position, Player* aim);
	CollisionConsequence Collision(GameObject* other) override;
	void Update(float dt) override;
	inline const sf::Color& GetColor() const { return m_Body.getFillColor(); }	
};
