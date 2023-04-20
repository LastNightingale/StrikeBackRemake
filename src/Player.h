#pragma once
#include "GameObject.h"
#include "Bullet.h"
class Player : public GameObject
{
public:	
	sf::Vector2f m_toTop;
	sf::Vector2f m_toBot;
private:	
	sf::RectangleShape m_Body;
public:
	Player();
	CollisionConsequence Collision(GameObject* other) override;
	void AddToRenderList(RenderList& list) override;
	void Update(float dt) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); }
	Bullet* Shoot(Colors color);
	inline sf::Vector2f GetPosition() const { return m_Body.getPosition(); }
};