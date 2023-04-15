#include "Spawner.h"
#include "Bullet.h"

Spawner::Spawner()
{
	m_Area.setSize({ 50, 900 });
	m_Area.setPosition({ 1400, 50 });
}

CollisionConsequence Spawner::Collision(GameObject* other)
{
	return { static_cast<bool>(dynamic_cast<Bullet*>(other)) , Consequenses::NO_CONSEQUENCE};
}

Enemy* Spawner::SpawnEnemy()
{
	return new Enemy(rand() % (int)(m_Area.getPosition().y + m_Area.getSize().y - (38 + 50) ) +
		(int)(m_Area.getPosition().y + (38 + 50) ), static_cast<Colors>(rand() % 5)); 
}

//new Enemy(rand() % 674 + 113, static_cast<Colors>(rand() % 5))