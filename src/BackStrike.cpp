#include "BackStrike.h"
#include <cmath>

BackStrike::BackStrike(sf::Vector2f position, Player* aim)
{
	m_Body.setFillColor(sf::Color::Magenta);
	m_Body.setSize({ 40, 40 });
	m_Body.setOrigin(20, 20);
	m_Body.setPosition(position);
	m_Aim = aim;
}

CollisionConsequence BackStrike::Collision(GameObject* other)
{
	return { false, Consequenses::NO_CONSEQUENCE };
}

void BackStrike::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Body);
}

void BackStrike::Update(float dt)
{
	sf::Vector2f AimPosition = m_Aim->GetPosition() - m_Body.getPosition();
	double length = sqrt(pow(AimPosition.x, 2) + pow(AimPosition.y, 2));
	m_Body.move(AimPosition.x / length * dt * 500.f, AimPosition.y / length * dt * 500.f);
}
