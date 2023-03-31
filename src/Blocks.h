#pragma once
#include <sfml/Graphics.hpp>
class InnerBlock
{
private:
	sf::RectangleShape m_Body;
public:
	InnerBlock() = default;
	InnerBlock(sf::Vector2f position, sf::Color color)
	{
		m_Body.setSize({ 50, 50 });
		m_Body.setOrigin({25, 25 });
		m_Body.setPosition(position);
		m_Body.setFillColor(color);
	}
	const sf::RectangleShape& GetBody() { return m_Body; }
};

class OuterBlock
{
private:
	sf::RectangleShape m_Body;
public:
	OuterBlock() = default;
	OuterBlock(sf::Vector2f position)
	{
		m_Body.setSize({ 100, 100 });
		m_Body.setOrigin({50, 50 });
		m_Body.setPosition(position);
		m_Body.setOutlineColor(sf::Color::White);
		m_Body.setOutlineThickness(3);
		m_Body.setFillColor(sf::Color::Black);
	}
	void SetColor(sf::Color color)
	{
		m_Body.setFillColor(color);
	}
	const sf::RectangleShape& GetBody() { return m_Body; }
};