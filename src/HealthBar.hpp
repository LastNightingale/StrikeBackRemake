#pragma once
#include "GameObject.h"
#include <array>

class HealthBar : public GameObject
{
private:
	sf::RectangleShape m_Body;
	sf::RectangleShape m_HealthBody;
public:
	HealthBar();
	void AddToRenderList(RenderList& list) override;
	void GetHit();
};
