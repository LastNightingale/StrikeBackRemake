#pragma once
#include <sfml/Graphics.hpp>
class InnerBlock
{
private:
	sf::RectangleShape m_Body;
public:
	InnerBlock() = default;
	InnerBlock(sf::Vector2f position, const sf::Color& color)
	{
		m_Body.setSize({ BlockParametrs::InnerBlockSize, BlockParametrs::InnerBlockSize });
		m_Body.setOrigin({ BlockParametrs::InnerBlockSize / 2.f, BlockParametrs::InnerBlockSize / 2.f });
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
		m_Body.setSize({ BlockParametrs::OuterBlockSize, BlockParametrs::OuterBlockSize });
		m_Body.setOrigin({ BlockParametrs::OuterBlockSize / 2.f, BlockParametrs::OuterBlockSize / 2.f });
		m_Body.setPosition(position);
		m_Body.setOutlineColor(sf::Color::White);
		m_Body.setOutlineThickness(BlockParametrs::OuterBlockThickness);
		m_Body.setFillColor(sf::Color::Black);
	}
	void SetColor(const sf::Color& color)
	{
		m_Body.setFillColor(color);
	}
	const sf::RectangleShape& GetBody() { return m_Body; }
};