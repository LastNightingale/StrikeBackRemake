#pragma once
#include "Physical.h"

class Destroyer : public Physical
{
public:
	Destroyer();
	void Update(float dt) override {};
	void AddToRenderList(RenderList& list) override {};
	CollisionConsequence Collision(GameObject* other) override;
};


