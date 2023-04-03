#pragma once
#include "GameObject.h"
#include "Blocks.h"
class Block : public GameObject
{
public:
	bool isActive = false;
private:
	InnerBlock m_Inner;
	OuterBlock m_Outer;	
public:
	Block(sf::Vector2f position, sf::Color color);	
	void ChooseColor();
	void UnchooseColor();
	void AddToRenderList(RenderList& list) override;
};