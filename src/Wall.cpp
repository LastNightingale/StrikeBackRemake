#include "Wall.h"
#include "Player.h"

Wall::Wall(sf::Vector2f size, sf::Vector2f position)
{
	m_Body.setSize(size);
	m_Body.setPosition(position);
}

CollisionConsequence Wall::Collision(GameObject* other)
{
	if (Player* player = dynamic_cast<Player*>(other))
	{
		if (player->GetPosition().y > this->m_Body.getPosition().y)
			player->m_toTop = { 0.f, 0.f };
		else if (player->GetPosition().y < this->m_Body.getPosition().y)
			player->m_toBot = { 0.f, 0.f };		
	}
	return { false, Consequenses::NO_CONSEQUENCE };
}
