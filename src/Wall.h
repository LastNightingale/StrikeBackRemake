#pragma once
#include "Physical.h"

class Wall : public Physical
{
public:
	Wall(sf::Vector2f size, sf::Vector2f position);
	void Update(float dt) override {};
	//void AddToRenderList(RenderList& list) override {};  //won't be visible later
	CollisionConsequence Collision(GameObject* other) override;
};
