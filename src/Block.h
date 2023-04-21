#pragma once
#include "GameObject.h"
#include "SeparatedBlocks.h"
class Block : public GameObject
{
public:
	bool isActive = false;
private:
	InnerBlock m_Inner;
	OuterBlock m_Outer;	
public:
	Block(sf::Vector2f position, sf::Color color);	
	void ColorChoose();
	void ColorUnchoose();
	void AddToRenderList(RenderList& list) override;
};