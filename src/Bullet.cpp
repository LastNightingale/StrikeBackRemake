#include "Bullet.h"
#include "Enemy.h"

Bullet::Bullet(float y, Colors color)
{
	m_Body.setPosition({ 280.f, y });
	m_Body.setFillColor(ColorBinds[color]);
	m_Body.setSize({ 10, 10 });
	m_Body.setOrigin(5, 5);
}

CollisionConsequence Bullet::Collision(GameObject* other)
{
	return { static_cast<bool>(dynamic_cast<Enemy*>(other)), Consequenses::NO_CONSEQUENCE };
}

void Bullet::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Body);
}

void Bullet::Update(float dt)
{
	this->m_Body.move(1000 * dt, 0);
}
