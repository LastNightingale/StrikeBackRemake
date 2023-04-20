#pragma once
#include "Block.h"
#include "Player.h"
#include "Spawner.h"
#include "Wall.h"
#include <vector>
#include <mutex>
#include <queue>
#include "Semaphore.h"

#define Color_Amount 5
#define Unmovables 5

class Game
{
private:
	std::vector<GameObject*> m_Objects;
	std::vector<GameObject*> m_DestroyedObjects;
	sf::RenderWindow m_Window{ sf::VideoMode(1400,950), "Strike Back Remake", sf::Style::Default };
	sf::Clock m_Clock;
	Player* m_Player;
	Spawner* m_Spawner;
	std::mutex m_Mutex;
	Semaphore m_Semaphore;
	unsigned int m_Bullets;
	unsigned int m_CurrentColor;
	float m_Spawntime;
	float m_Dt;
	unsigned int m_Health;
	bool m_isGoing;
public:
	Game();
	void Run();	
private:
	void SetStartObjects();
	void SetCurrentColor(unsigned int color);
	void GameCollision();
	void Update();
	void Render();
};