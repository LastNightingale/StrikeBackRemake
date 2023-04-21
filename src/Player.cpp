#include "Player.h"
#include "BackStrike.h"

Player::Player()
{
	m_Body.setSize({ PlayerParametrs::PlayerSize, PlayerParametrs::PlayerSize });
	m_Body.setOrigin(PlayerParametrs::PlayerSize / 2.f, PlayerParametrs::PlayerSize / 2.f);
	m_Body.setPosition(sf::Vector2f(PlayerParametrs::PlayerPositionX, PlayerParametrs::PlayerPositionY));
	m_Body.setFillColor(sf::Color::Blue);
}

CollisionConsequence Player::Collision(GameObject* other)
{
	if (BackStrike* bstr = dynamic_cast<BackStrike*>(other))
		return { true, Consequenses::GET_HIT };
	else return { false, Consequenses::NO_CONSEQUENCE };
	
}

void Player::Update(float dt)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) this->m_Body.move({ 0.f , -500.f * dt });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) this->m_Body.move({ 0.f , 500.f * dt });*/
	this->m_Body.move((m_toBot + m_toTop) * dt);
}

Bullet* Player::Shoot(Colors color)
{
	return new Bullet(m_Body.getPosition().y, color);
}
