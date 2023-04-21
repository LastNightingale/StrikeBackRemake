#include "Bullet.h"
#include "Enemy.h"

Bullet::Bullet(float y, Colors color)
{
	m_Body.setPosition({ PlayerParametrs::PlayerPositionX, y });
	m_Body.setFillColor(ColorBinds[color]);
	m_Body.setSize({ BulletParametrs::BulletSize, BulletParametrs::BulletSize });
	m_Body.setOrigin(BulletParametrs::BulletSize / 2.f, BulletParametrs::BulletSize / 2.f);
}

CollisionConsequence Bullet::Collision(GameObject* other)
{
	return { static_cast<bool>(dynamic_cast<Enemy*>(other)), Consequenses::NO_CONSEQUENCE };
}

//void Bullet::AddToRenderList(RenderList& list)
//{
//	list.Rects.push_back(m_Body);
//}

void Bullet::Update(float dt)
{
	this->m_Body.move(BulletParametrs::BulletSpeed * dt, 0);
}
