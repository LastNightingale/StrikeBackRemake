#include "Enemy.h"

Enemy::Enemy(float y, Colors color)
{	
	m_IsWrong = false;
	m_Body.setFillColor(ColorBinds[color]);
	m_Body.setSize({ 75, 75 });
	m_Body.setOrigin(37.5, 37.5);
	m_Body.setPosition({ 1400.f, y });
}

bool Enemy::Collision(GameObject* other)
{
	if (Bullet* bullet = dynamic_cast<Bullet*>(other))
	{
		if (GetColor() != bullet->GetColor())
		{
			this->m_IsWrong = true;			
		}
		return true;
	}
	else return false;
}

void Enemy::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Body);
}

void Enemy::Update(float dt)
{
	this->m_Body.move(-400 * dt, 0);
}
