#include "Game.h"
#include "Enemy.h"
#include "Player.h"

Game::Game()
{
	m_isGoing = true;
	m_Spawntime = 0.f;
	m_CurrentColor = 0;
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
	/*Update(m_Dt);
	Render();*/
}

void Game::SetStartObjects()
{
	for (int i = 0; i < Color_Amount; i++)
	{
		m_Objects.push_back(new Block(sf::Vector2f(140.f, (900 - Color_Amount * 100 - (Color_Amount - 1) * 50) / 2 + 50 + 150 * i),
			ColorBinds[static_cast<Colors>(i)]));
	}
	m_Player = new Player();
	m_Objects.push_back(m_Player);
}

void Game::SetCurrentColor(unsigned int color)
{
	m_Mutex.lock();
	Block* lastblock = reinterpret_cast<Block*>(m_Objects[m_CurrentColor]);
	lastblock->UnchooseColor();
	m_CurrentColor = color;
	Block* currentblock = reinterpret_cast<Block*>(m_Objects[m_CurrentColor]);
	currentblock->ChooseColor();
	m_Mutex.unlock();
}

void Game::GameCollision()
{
	for (GameObject* object : m_DestroyedObjects)
	{
		for (int i = 0; i < m_Objects.size(); i++)
		{
			if (object == m_Objects[i])
			{
				if (Enemy* slain = dynamic_cast<Enemy*>(object))
					if (slain->m_IsWrong)
					{
						m_Objects.push_back(slain->ReturnHit(m_Player));
					}
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
		m_Mutex.lock();
		m_Dt = m_Clock.getElapsedTime().asSeconds();
		m_Clock.restart();
		for (int i = 5; i < m_Objects.size(); i++)
		{
			for (int j = 5; j < m_Objects.size(); j++)
			{
				if (m_Objects[i]->GetGlobalBounds().intersects(m_Objects[j]->GetGlobalBounds()))
				{
					if (m_Objects[i]->Collision(m_Objects[j]))
					{
						m_DestroyedObjects.push_back(m_Objects[j]);
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
			m_Objects.push_back(new Enemy(rand() % 674 + 113, static_cast<Colors>(rand() % 4)));
			m_Spawntime = 0.f;
		}
		m_Mutex.unlock();
	}	
		
}

void Game::Render()
{
	while (m_Window.isOpen())
	{
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
			if (event.type == sf::Event::EventType::Closed || m_Player->m_Health == 0) m_Window.close();
			if (event.type == sf::Event::EventType::MouseButtonReleased)
				if (event.key.code == sf::Mouse::Button::Left)
				{
					m_Mutex.lock();
					m_Objects.push_back(m_Player->Shoot(static_cast<Colors>(m_CurrentColor)));
					m_Mutex.unlock();
				}					
			if (event.type == sf::Event::EventType::KeyPressed)
				if (KeyBinds.find(event.key.code) != KeyBinds.end())
					SetCurrentColor(KeyBinds[event.key.code]);
		}

	}
}
