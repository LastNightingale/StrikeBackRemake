#pragma once
#include "Physical.h"
#include "Bullet.h"
#include "BackStrike.h"

class Enemy : public Physical
{
private:
	//sf::RectangleShape m_Body;
public:
	Enemy(float y, Colors color);
	CollisionConsequence Collision(GameObject* other) override;
	//void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	BackStrike* ReturnHit(Player* Aim) { return new BackStrike(m_Body.getPosition(), Aim); }
	//inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	inline const sf::Color& GetColor() const { return m_Body.getFillColor(); }
};