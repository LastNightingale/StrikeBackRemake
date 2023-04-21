#include "Destroyer.h"
#include "Enemy.h"

Destroyer::Destroyer()
{
	m_Body.setSize({DestroyerParametrs::DestroyerSizeX, DestroyerParametrs::DestroyerSizeY});
	m_Body.setPosition({ DestroyerParametrs::DestroyerPositionX, DestroyerParametrs::DestroyerPositionY });
}

CollisionConsequence Destroyer::Collision(GameObject* other)
{
	if (Enemy* enemy = dynamic_cast<Enemy*>(other))
		return { true, Consequenses::GET_HIT };
	else return {false, Consequenses::NO_CONSEQUENCE};
}
