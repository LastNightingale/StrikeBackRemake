#pragma once
#pragma once
#include "GameObject.h"
#include "Player.h"

class BackStrike : public GameObject
{
private:
	sf::RectangleShape m_Body;
	Player* m_Aim;
public:
	BackStrike(sf::Vector2f position, Player* aim);
	bool Collision(GameObject* other) override;
	void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	inline const sf::Color& GetColor() const { return m_Body.getFillColor(); }	
};
