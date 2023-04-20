#pragma once
#include "Physical.h"
#include "Player.h"

class BackStrike : public Physical
{
private:
	//sf::RectangleShape m_Body;
	Player* m_Aim;
public:
	BackStrike(sf::Vector2f position, Player* aim);
	CollisionConsequence Collision(GameObject* other) override;
	//void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	//inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	inline const sf::Color& GetColor() const { return m_Body.getFillColor(); }	
};
