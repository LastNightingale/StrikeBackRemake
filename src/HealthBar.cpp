#include "HealthBar.hpp"

HealthBar::HealthBar()
{
	m_Body.setPosition({BarParametrs::HealthBarPositionX, BarParametrs::HealthBarPositionY});
	m_Body.setSize({BarParametrs::HealthBarSizeX, BarParametrs::HealthBarSizeY});
	m_Body.setFillColor(sf::Color::Transparent);
	m_Body.setOutlineColor(sf::Color::White);
	m_Body.setOutlineThickness(BarParametrs::BarOutlineThickness);

	m_HealthBody.setPosition({ BarParametrs::HealthBarPositionX, BarParametrs::HealthBarPositionY });
	m_HealthBody.setSize({ BarParametrs::HealthBarSizeX, BarParametrs::HealthBarSizeY });
	m_HealthBody.setFillColor(sf::Color::Red);

}


void HealthBar::AddToRenderList(RenderList& list)
{		
	list.Rects.push_back(m_HealthBody);
	list.Rects.push_back(m_Body);
}

void HealthBar::GetHit()
{
	m_HealthBody.setSize({ m_HealthBody.getSize().x - (BarParametrs::HealthBarSizeX / GameParametrs::Hit) , m_HealthBody.getSize().y });
}
