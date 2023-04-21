#include "Enemy.h"

Enemy::Enemy(float y, Colors color)
{	
	m_Body.setFillColor(ColorBinds[color]);
	m_Body.setSize({ EnemyParametrs::EnemySize, EnemyParametrs::EnemySize });
	m_Body.setOrigin(EnemyParametrs::EnemySize / 2.f, EnemyParametrs::EnemySize / 2.f);
	m_Body.setPosition({ GameParametrs::ScreenWidth, y });
}

CollisionConsequence Enemy::Collision(GameObject* other)
{
	if (Bullet* bullet = dynamic_cast<Bullet*>(other))
	{
		if (GetColor() != bullet->GetColor())
		{
			return { true, Consequenses::WRONG_COLOR };
		}
		else return { true, Consequenses::NO_CONSEQUENCE };
	}
	else return { false , Consequenses::NO_CONSEQUENCE };
	
}

void Enemy::Update(float dt)
{
	this->m_Body.move(EnemyParametrs::EnemySpeed * dt, 0);
}
