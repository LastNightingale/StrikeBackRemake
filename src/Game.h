#pragma once
#include "Block.h"
#include "Player.h"
#include <vector>
#include <mutex>

#define Color_Amount 5

class Game
{
private:
	std::vector<GameObject*> m_Objects;
	std::vector<GameObject*> m_DestroyedObjects;
	sf::RenderWindow m_Window{ sf::VideoMode(1400,900), "Strike Back Updated", sf::Style::Default };
	Player* m_Player;
	std::mutex m_Mutex;
	unsigned int m_Bullets;
	unsigned int m_CurrentColor;
	float m_Spawntime;
	float m_Dt;
	bool m_isGoing;
public:
	Game();
	void Run();	
private:
	void SetStartObjects();
	void SetCurrentColor(unsigned int color);
	void GameCollision();
	void Update(float dt);
	void Render();
};