#include "Destroyer.h"

CollisionConsequence Destroyer::Collision(GameObject* other)
{
	return {false, Consequenses::NO_CONSEQUENCE};
}
