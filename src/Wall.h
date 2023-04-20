#pragma once
#include "Physical.h"

class Wall : public Physical
{
public:
	void Update(float dt) override {};
	void AddToRenderList(RenderList& list) override {};
	CollisionConsequence Collision(GameObject* other) override;
};
