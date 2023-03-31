#include "Block.h"

Block::Block(sf::Vector2f position, sf::Color color)
{
	m_Inner = InnerBlock(position, color);
	m_Outer = OuterBlock(position);
}

void Block::ChooseColor()
{
	isActive = true;
	m_Outer.SetColor({ 70, 70, 70 });
}

void Block::UnchooseColor()
{
	isActive = false;
	m_Outer.SetColor(sf::Color::Black);
}

void Block::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Outer.GetBody());
	list.Rects.push_back(m_Inner.GetBody());
}
