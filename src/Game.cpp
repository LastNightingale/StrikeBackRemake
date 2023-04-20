#include "Game.h"
#include "Enemy.h"
#include "Player.h"
#include "Destroyer.h"
#include "Spawner.h"
#include <iostream>

Game::Game()
{
	m_isGoing = true;
	m_Spawntime = 0.f;
	m_CurrentColor = 0;
	m_Health = 100;
	SetStartObjects();
	SetCurrentColor(0);
}

void Game::Run()
{
	srand(time(NULL));			
	std::thread UpdateThread([this]()
		{
			this->Update(); 
		});
	this->Render();
	UpdateThread.join();
}

void Game::SetStartObjects()
{
	for (int i = 0; i < Color_Amount; i++)
	{
		m_Objects.push_back(new Block(sf::Vector2f(140.f, 50 + (900 - Color_Amount * 100 - (Color_Amount - 1) * 50) / 2 + 50 + 150 * i),
			ColorBinds[static_cast<Colors>(i)]));
	}
	m_Spawner = new Spawner();
	m_Objects.push_back(m_Spawner);
	m_Objects.push_back(new Destroyer());
	m_Objects.push_back(new Wall({ 500, 10 }, { 140, 900 }));
	m_Objects.push_back(new Wall({ 500, 10 }, { 140, 100 }));
	m_Player = new Player();
	m_Objects.push_back(m_Player);
}

void Game::SetCurrentColor(unsigned int color)
{
	Block* lastblock = reinterpret_cast<Block*>(m_Objects[m_CurrentColor]);
	lastblock->ColorUnchoose();
	m_CurrentColor = color;
	Block* currentblock = reinterpret_cast<Block*>(m_Objects[m_CurrentColor]);
	currentblock->ColorChoose();
}

void Game::GameCollision()
{
	for (GameObject* object : m_DestroyedObjects)
	{
		for (int i = 0; i < m_Objects.size(); i++)
		{
			if (object == m_Objects[i])
			{				
				GameObject* temp = m_Objects[i];
				m_Objects[i] = m_Objects[m_Objects.size() - 1];
				m_Objects[m_Objects.size() - 1] = temp;
				m_Objects.pop_back();
				delete temp;
				break;
			}
		}
	}
	m_DestroyedObjects.clear();
}

void Game::Update()
{	
	while (m_isGoing)
	{
		m_Semaphore.Wait();
		m_Mutex.lock();
		m_Dt = m_Clock.getElapsedTime().asSeconds();
		m_Clock.restart();
		for (int i = Unmovables; i < m_Objects.size(); i++)
		{
			for (int j = Unmovables; j < m_Objects.size(); j++)
			{
				if (m_Objects[i]->GetGlobalBounds().intersects(m_Objects[j]->GetGlobalBounds()))
				{
					CollisionConsequence cc = m_Objects[i]->Collision(m_Objects[j]);
					if (cc.toDestroyObject)
					{
						m_DestroyedObjects.push_back(m_Objects[j]);
					}	
					if (cc.typeConsequence == Consequenses::GET_HIT)
						m_Health -= 10;
					if (cc.typeConsequence == Consequenses::WRONG_COLOR)
					{
						auto slain = dynamic_cast<Enemy*>(m_Objects[i]);
						m_Objects.push_back(slain->ReturnHit(m_Player));
					}						
				}
			}
		}
		GameCollision();
		for (GameObject* object : m_Objects)
			object->Update(m_Dt);
		m_Spawntime += m_Dt;
		if (m_Spawntime >= 1.0)
		{
			m_Objects.push_back(m_Spawner->SpawnEnemy());
			m_Spawntime = 0.f;
		}
		m_Mutex.unlock();
	}	
		
}

void Game::Render()
{
	while (m_Window.isOpen())
	{
		m_Semaphore.Signal();
		m_Window.clear(sf::Color::Black);
		RenderList list;
		m_Mutex.lock();
		for (auto& object = m_Objects.rbegin(); object != m_Objects.rend(); object++)
			(*object)->AddToRenderList(list);
		m_Mutex.unlock();
		for (sf::RectangleShape& rect : list.Rects)
			m_Window.draw(rect);
		m_Window.display();
		//display then handle for next loop		
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			m_Mutex.lock();
			if (event.type == sf::Event::EventType::Closed || m_Health == 0) m_Window.close();
			if (event.type == sf::Event::EventType::MouseButtonReleased)
			{
				if (event.key.code == sf::Mouse::Button::Left)
				{
					m_Objects.push_back(m_Player->Shoot(static_cast<Colors>(m_CurrentColor)));
				}				
			}		
			if (event.type == sf::Event::EventType::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
					m_Player->m_toTop = { 0.f, 0.f };
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
					m_Player->m_toBot = { 0.f, 0.f };
			}
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (KeyBinds.find(event.key.code) != KeyBinds.end())
					SetCurrentColor(KeyBinds[event.key.code]);
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
					m_Player->m_toTop = { 0.f, -500.f };
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
					m_Player->m_toBot = { 0.f, 500.f };
			}
				
			m_Mutex.unlock();
		}

	}
}
