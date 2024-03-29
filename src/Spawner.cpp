#include "Spawner.h"
#include "Bullet.h"

Spawner::Spawner()
{
	m_Body.setSize({ SpawnerParametrs::SpawnerSizeX, SpawnerParametrs::SpawnerSizeY });
	m_Body.setPosition({ SpawnerParametrs::SpawnerPositionX, SpawnerParametrs::SpawnerPositionY });
}

CollisionConsequence Spawner::Collision(GameObject* other)
{
	return { static_cast<bool>(dynamic_cast<Bullet*>(other)) , Consequenses::NO_CONSEQUENCE};
}

Enemy* Spawner::SpawnEnemy()
{
	return new Enemy(rand() % (int)(SpawnerParametrs::SpawnerSizeY) +
		(int)(SpawnerParametrs::SpawnerPositionY), static_cast<Colors>(rand() % GameParametrs::ColorAmount)); 
}

//new Enemy(rand() % 674 + 113, static_cast<Colors>(rand() % 5))

//return new Enemy(rand() % (int)(m_Body.getPosition().y + m_Body.getSize().y - (38 + 50)) +
//	(int)(m_Body.getPosition().y + (38 + 50)), static_cast<Colors>(rand() % 5));