#include "Destroyer.h"
#include "Enemy.h"

Destroyer::Destroyer()
{
	m_Area.setSize({75, 950});
	m_Area.setPosition({ 242.5, 0 });
}

CollisionConsequence Destroyer::Collision(GameObject* other)
{
	if (Enemy* enemy = dynamic_cast<Enemy*>(other))
		return { true, Consequenses::GET_HIT };
	else return {false, Consequenses::NO_CONSEQUENCE};
}
