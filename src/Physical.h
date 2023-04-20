#pragma once
#include "GameObject.h"

class Physical : public GameObject
{
protected:
	sf::RectangleShape m_Body;
public:
	void AddToRenderList(RenderList& list) override;
	inline sf::FloatRect GetGlobalBounds() override { return m_Body.getGlobalBounds(); };
};