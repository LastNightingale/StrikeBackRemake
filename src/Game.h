#pragma once
#include "Block.h"
#include "Player.h"
#include "Spawner.h"
#include "HealthBar.hpp"
#include "Wall.h"
#include <vector>
#include <mutex>
#include <queue>
#include "Semaphore.h"

class Game
{
private:
	std::vector<GameObject*> m_Objects;
	std::vector<GameObject*> m_DestroyedObjects;
	sf::RenderWindow m_Window{ sf::VideoMode(GameParametrs::ScreenWidth, GameParametrs::ScreenHeight), "Strike Back Remake", sf::Style::Default };
	sf::Clock m_Clock;
	HealthBar* m_HealthBar;
	//Bar* m_BulletBar;
	Player* m_Player;
	Spawner* m_Spawner;
	std::mutex m_Mutex;
	Semaphore m_Semaphore;
	unsigned int m_Bullets;
	unsigned int m_CurrentColor;
	float m_Spawntime;
	float m_Dt;
	float m_Health;
	bool m_isGoing;
public:
	Game();
	void Run();	
private:
	void SetStartObjects();
	void SetCurrentColor(unsigned int color);
	void GameCollision();
	void GetHit();
	void Update();
	void Render();
	void FinishGame();
};