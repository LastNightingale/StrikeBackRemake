#include "Player.h"
#include "BackStrike.h"

Player::Player()
{
	m_Health = 100;
	m_Body.setSize(sf::Vector2f(75, 75));
	m_Body.setOrigin(37.5, 37.5);
	m_Body.setPosition(sf::Vector2f(280, 450));
	m_Body.setFillColor(sf::Color::Blue);
}

CollisionConsequence Player::Collision(GameObject* other)
{
	if (BackStrike* bstr = dynamic_cast<BackStrike*>(other))
		return { true, Consequenses::GET_HIT };
	else return { false, Consequenses::NO_CONSEQUENCE };
	
}

void Player::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Body);
}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) this->m_Body.move({ 0.f , -500.f * dt });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) this->m_Body.move({ 0.f , 500.f * dt });
}

Bullet* Player::Shoot(Colors color)
{
	return new Bullet(m_Body.getPosition().y, color);
}
